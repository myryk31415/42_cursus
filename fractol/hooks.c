/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:13:00 by padam             #+#    #+#             */
/*   Updated: 2023/11/17 16:26:25 by padam            ###   ########.fr       */
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
	// if (mlx_is_key_down(flags->mlx, MLX_KEY_Q))
	// 	flags->zoom *= 1.2;
	// if (mlx_is_key_down(flags->mlx, MLX_KEY_E))
	// 	flags->zoom /= 1.2;
	flags->x = x1 - (x - (int)(flags->img->width) / 2) / flags->zoom;
	flags->y = y1 - (y - (int)(flags->img->height) / 2) / flags->zoom;
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
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && ++flags->update)
		flags->julia_y -= 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) && ++flags->update)
		flags->julia_y += 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) && ++flags->update)
		flags->julia_x -= 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) && ++flags->update)
		flags->julia_x += 10 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		flags->y_diff -= 100;
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
		flags->y_diff += 100;
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		flags->x_diff -= 100;
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
		flags->x_diff += 100;
	flags->update++;
	if (mlx_is_key_down(mlx, MLX_KEY_H))
	{
		flags->zoom = 400;
		flags->x = 0;
		flags->y = 0;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_O))
	{
		flags->max_iter++;
		flags->max_iter_change = 1;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_I) && flags->max_iter)
	{
		flags->max_iter--;
		flags->max_iter_change = 1;
	}
	else
		flags->update--;
	flags->x += flags->x_diff / flags->zoom;
	flags->y += flags->y_diff / flags->zoom;
	if (flags->max_iter_change)
	{
		flags->max_iter_change = 0;
		free(flags->pixelcount_i);
		flags->pixelcount_i = ft_calloc(flags->max_iter + 1, sizeof(int));
	}
	if (flags->update || flags->x_diff || flags->y_diff)
	{
		update_image(flags);
		flags->update = 0;
	}
}
