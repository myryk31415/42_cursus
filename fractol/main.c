/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:48:05 by padam             #+#    #+#             */
/*   Updated: 2023/11/09 21:16:30 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	update_image(mlx_image_t *img, t_flags *flags)
{
	int		x;
	int		y;
	double	x1;
	double	y1;
	int		i;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			x1 = (x - flags->width / 2) / flags->zoom + flags->x;
			y1 = (y - flags->height / 2) / flags->zoom + flags->y;
			i = mandelbrot_iterations(x1, y1, flags);
			if (i == flags->max_iter)
				img->pixels[y * img->width + x] = 0;
			else
				img->pixels[y * img->width + x] = 0xFFFFFF / flags->max_iter * i;
			y++;
		}
		x++;
	}
	return (0);

}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	// if (mlx_is_key_down(param, MLX_KEY_UP))
	// 	g_img->instances[0].y -= 5;
	// if (mlx_is_key_down(param, MLX_KEY_DOWN))
	// 	g_img->instances[0].y += 5;
	// if (mlx_is_key_down(param, MLX_KEY_LEFT))
	// 	g_img->instances[0].x -= 5;
	// if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	// 	g_img->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_flags		flags;

	if (argc == 7)
		argv++;
	// if (!check_parameters(argc, argv))
	// {
	// 	put_parameters();
	// 	return (0);
	// }

	mlx = mlx_init(WIDTH, HEIGHT, "fract\'ol", false);
	// if (!mlx)
	// 	ft_error();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
	// mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
