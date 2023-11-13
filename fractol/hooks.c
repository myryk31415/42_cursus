/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:13:00 by padam             #+#    #+#             */
/*   Updated: 2023/11/13 21:45:43 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *flags_in)
{
	t_flags	*flags;

	flags = flags_in;
	if (ydelta + xdelta < 0 && ++flags->update)
		flags->zoom *= 1 - (ydelta + xdelta) / 10;
	if (ydelta + xdelta > 0 && ++flags->update) //flags->zoom > (ydelta + xdelta) * flags->zoom && ++flags->update)
		flags->zoom /= 1 + (ydelta + xdelta) / 10; //-= (ydelta + xdelta) * flags->zoom;
}

void	hook(void *flags_in)
{
	t_flags	*flags;
	mlx_t	*mlx;

	flags = flags_in;
	flags->x_old = flags->x;
	flags->y_old = flags->y;
	flags->zoom_old = flags->zoom;
	flags->max_iter_old = flags->max_iter;
	mlx = flags->mlx;
	if (flags->img->height != (const uint32_t)mlx->height
		|| flags->img->width != (const uint32_t)mlx->width)
		new_image(flags);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		stop_program("Program stopped by user\n", flags);
	flags->update++;
	if (mlx_is_key_down(mlx, MLX_KEY_H))
	{
		flags->zoom = 400;
		flags->x = 0;
		flags->y = 0;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_O))
		flags->max_iter++;
	else if (mlx_is_key_down(mlx, MLX_KEY_I) && flags->max_iter)
		flags->max_iter--;
	else if (mlx_is_key_down(mlx, MLX_KEY_UP))
		flags->julia_y -= 10 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		flags->julia_y += 10 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		flags->julia_x -= 10 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		flags->julia_x += 10 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_W))
		flags->y -= 100 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
		flags->y += 100 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		flags->x -= 100 / flags->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
		flags->x += 100 / flags->zoom;
	else
		flags->update--;
	if (flags->max_iter != flags->max_iter_old)
	{
		free(flags->pixelcount_i);
		flags->pixelcount_i = malloc(sizeof(int) * flags->max_iter);
	}
	if (flags->update)
	{
		update_image(flags);
		flags->update = 0;
	}
}
