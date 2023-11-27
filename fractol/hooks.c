/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:13:00 by padam             #+#    #+#             */
/*   Updated: 2023/11/24 18:48:30 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *flags_in)
{
	t_flags	*flags;
	int		x;
	int		y;
	double	x1;
	double	y1;

	flags = flags_in;
	mlx_get_mouse_pos(flags->mlx, &x, &y);
	x1 = (x - (int)(flags->img->width) / 2) / flags->zoom + flags->x;
	y1 = (y - (int)(flags->img->height) / 2) / flags->zoom + flags->y;
	if (ydelta + xdelta < 0 && ++flags->update)
		flags->zoom *= 1 - (ydelta + xdelta) / 10;
	if (ydelta + xdelta > 0 && ++flags->update)
		flags->zoom /= 1 + (ydelta + xdelta) / 10;
	flags->x = x1 - (x - (int)(flags->img->width) / 2) / flags->zoom;
	flags->y = y1 - (y - (int)(flags->img->height) / 2) / flags->zoom;
}

static void	keybinds_two(mlx_t *mlx, t_flags *flags)
{
	flags->update++;
	if (mlx_is_key_down(mlx, MLX_KEY_H))
	{
		flags->zoom = 400;
		flags->x = 0;
		flags->y = 0;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_C))
		flags->color = flags->color * 0x100 % 0xFFFFFF;
	else if (mlx_is_key_down(mlx, MLX_KEY_O))
	{
		flags->max_iter++;
		free(flags->pixelcount_i);
		flags->pixelcount_i = ft_calloc(flags->max_iter + 1, sizeof(int));
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_I) && flags->max_iter)
	{
		flags->max_iter--;
		free(flags->pixelcount_i);
		flags->pixelcount_i = ft_calloc(flags->max_iter + 1, sizeof(int));
	}
	else
		flags->update--;
}

static void	keybinds_one(mlx_t *mlx, t_flags *flags)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W) && ++flags->update)
		flags->julia_y += 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_A) && ++flags->update)
		flags->julia_x -= 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_S) && ++flags->update)
		flags->julia_y -= 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_D) && ++flags->update)
		flags->julia_x += 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		flags->y_diff -= 100;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		flags->y_diff += 100;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		flags->x_diff -= 100;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		flags->x_diff += 100;
}

void	hook(void *flags_in)
{
	t_flags	*flags;
	mlx_t	*mlx;

	flags = flags_in;
	mlx = flags->mlx;
	flags->x_diff = 0;
	flags->y_diff = 0;
	if (flags->img->height != (const uint32_t)mlx->height
		|| flags->img->width != (const uint32_t)mlx->width)
		new_image(flags);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		stop_program("Program stopped by user\n", flags);
		return ;
	}
	keybinds_one(mlx, flags);
	keybinds_two(mlx, flags);
	flags->x += flags->x_diff / flags->zoom;
	flags->y += flags->y_diff / flags->zoom;
	if (flags->update || flags->x_diff || flags->y_diff)
	{
		update_image(flags);
		flags->update = 0;
	}
}
