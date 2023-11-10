/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:48:05 by padam             #+#    #+#             */
/*   Updated: 2023/11/10 16:44:54 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	update_image(t_flags *flags)
{
	int			x;
	int			y;
	double		x1;
	double		y1;
	int			i;
	u_int32_t	color[3] = {RED, GREEN, BLUE};

	y = 0;
	while (y < (int)(flags->img->height))
	{
		x = 0;
		while (x < (int)(flags->img->width))
		{
			x1 = (x - (int)(flags->img->width) / 2) / flags->zoom + flags->x;
			y1 = (y - (int)(flags->img->height) / 2) / flags->zoom + flags->y;
			i = mandelbrot_iterations(x1, y1, flags);
			if (i >= flags->max_iter)
				set_color(y * flags->img->width + x, BLACK, 0, flags);
			else
				set_color(y * flags->img->width + x, color[i % 3], 0, flags);
			x++;
		}
		y++;
	}
	return (0);
}

void	my_scrollhook(double xdelta, double ydelta, void *flags_in)
{
	t_flags	*flags;

	flags = flags_in;
	if (ydelta + xdelta != 0)
		flags->zoom -= (ydelta + xdelta) * flags->zoom;
}

void	hook(void *flags_in)
{
	t_flags	*flags;
	mlx_t	*mlx;

	flags = flags_in;
	mlx = flags->mlx;
	if (flags->img->height != (const uint32_t)mlx->height
		|| flags->img->width != (const uint32_t)mlx->width)
	{
		mlx_delete_image(mlx, flags->img);
		flags->img = mlx_new_image(mlx, mlx->width, mlx->height);
		mlx_image_to_window(mlx, flags->img, 0, 0);
	}
	update_image(flags);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		flags->y -= 100 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		flags->y += 100 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		flags->x -= 100 / flags->zoom;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		flags->x += 100 / flags->zoom;
}

int	main(int argc, char **argv)
{
	t_flags		flags;

	if (argc == 7)
		argv++;
	// if (!check_parameters(argc, argv))
	// {
	// 	put_parameters();
	// 	return (0);
	// }

	initialize_flags(&flags);
	flags.mlx = mlx_init(WIDTH, HEIGHT, "fract\'ol", true);
	if (!flags.mlx)
		return (0);
	flags.img = mlx_new_image(flags.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(flags.mlx, flags.img, 0, 0);
	update_image(&flags);
	mlx_scroll_hook(flags.mlx, &my_scrollhook, &flags);
	mlx_loop_hook(flags.mlx, hook, &flags);
	mlx_loop(flags.mlx);
	mlx_terminate(flags.mlx);
	return (0);
}
