/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:48:05 by padam             #+#    #+#             */
/*   Updated: 2023/11/16 00:20:16 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bordertrace(int x0, int y0, t_flags *flags)
{
	int	x;
	int	y;
	int	direction;
	int	count;
	int	count_zero;

	x = x0;
	y = y0;
	direction = 2;
	count_zero = 3;
	while (x != x0 && y != y0 && count_zero)
	{
		count = (x == (int)(flags->img->width - 1)) + (x == 0)
			+ (y == (int)(flags->img->height - 1)) + (y == 0);
		while (count++ < 4)
		{

		}
	}
}

void	fill_iterationcount(t_flags *flags)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	while (y < (int)(flags->img->height))
	{
		x = 0;
		while (x < (int)(flags->img->width))
		{
			i = get_iteration(x, y, flags);
			flags->pixelcount_i[i]++;
			// if (i == -2)
			// 	while (flags->iterationcount[y][++x] != -2)
			// 		flags->iterationcount[y][x] = flags->max_iter;
			x++;
		}
		y++;
	}
}

int	get_color(double hue)
{
	int	i;

	i = hue * 0xFFFFFF;
	// i =	90 * 255 * (1 - hue) * hue * hue * hue;
	// i *= 0x100;
	// i += 5 * 255 * (1 - hue) * (1 - hue) * hue * hue;
	// i *= 0x100;
	// i += 70 * 255 * (1 - hue) * (1 - hue) * (1 - hue) * hue;
	// printf("hue: %i\n", i);
	// i = (int)(255 * hue * hue * hue) * 0x10000;
	// i += (1 - hue) * (1 - hue) * 255;
	return (i);
}

void	color_image(t_flags *flags)
{
	int			x;
	int			y;
	int			i;
	double		hue;

	y = 0;
	while (y < (int)(flags->img->height))
	{
		x = 0;
		while (x < (int)(flags->img->width))
		{
			i = flags->iterationcount[y][x];
			if (i == flags->max_iter)
				set_color(y * flags->img->width + x, BLACK, 0, flags);
			else
			{
				hue = 0;
				while (i >= 0)
					hue += flags->pixelcount_i[i--];
				hue /= flags->total;
				set_color(y * flags->img->width + x, get_color(hue), 0, flags);
			}
			x++;
		}
		y++;
	}
}

void	update_image(t_flags *flags)
{
	int	i;

	i = 0;
	reset_flags_arrays(flags);
	fill_iterationcount(flags);
	flags->total = 0;
	while (i < flags->max_iter)
		flags->total += flags->pixelcount_i[i++];
	color_image(flags);
}

int	check_parameters(int argc, char **argv, t_flags *flags)
{
	int	i;

	if (argc < 2 || argc > 4)
		return (0);
	if (ft_strchr("jmb", argv[1][0]) && argv[1][1] == 0)
		flags->fractal = argv[1][0];
	else
		return (0);
	if (flags->fractal == 'j')
	{
		if (argc > 2)
		{
			i = -1;
			while (argv[2][++i])
				if (!ft_isdigit(argv[2][i]) && argv[2][i] != '-')
					return (0);
			flags->julia_x = ft_atoi(argv[2]) / 100;
		}
		if (argc == 4)
		{
			i = -1;
			while (argv[3][++i])
				if (!ft_isdigit(argv[3][i]) && argv[2][i] != '-')
					return (0);
			flags->julia_x = ft_atoi(argv[3]) / 100;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_flags		flags;

	printf("%i\n", argc);
	printf("%c\n", argv[1][0]);
	if (!check_parameters(argc, argv, &flags))
	{
		put_parameters();
		return (0);
	}
	initialize_flags(&flags);
	mlx_scroll_hook(flags.mlx, &my_scrollhook, &flags);
	mlx_loop_hook(flags.mlx, &hook, &flags);
	mlx_loop(flags.mlx);
	mlx_terminate(flags.mlx);
	return (0);
}
