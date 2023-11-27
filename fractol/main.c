/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:48:05 by padam             #+#    #+#             */
/*   Updated: 2023/11/24 18:18:50 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_iterationcount(t_flags *flags)
{
	int	x;
	int	y;
	int	i;

	y = (flags->img->height - 1) * (flags->y_diff > 0) - flags->y_diff;
	while (y < (int)(flags->img->height) && y >= 0)
	{
		x = (flags->img->width - 1) * (flags->x_diff > 0) - flags->x_diff;
		while (x < (int)(flags->img->width) && x >= 0)
		{
			i = get_iteration(x, y, flags);
			flags->pixelcount_i[i]++;
			if (flags->x_diff < 0)
				x--;
			else
				x++;
		}
		if (flags->y_diff < 0)
			y--;
		else
			y++;
	}
}

static void	color_image(t_flags *flags)
{
	int		x;
	int		y;
	int		i;
	double	hue;

	y = -1;
	while (++y < (int)(flags->img->height))
	{
		x = -1;
		while (++x < (int)(flags->img->width))
		{
			i = flags->iterationcount[y][x];
			if (i == flags->max_iter)
				set_color(y * flags->img->width + x, BLACK, flags);
			else
			{
				hue = 0;
				while (i >= 0)
					hue += flags->pixelcount_i[i--];
				hue /= flags->total;
				set_color(y * flags->img->width + x,
					get_color(hue, flags), flags);
			}
		}
	}
}

static void	copy_iterationcount(t_flags *flags)
{
	int	x;
	int	y;
	int	xd;
	int	yd;

	xd = flags->x_diff;
	yd = flags->y_diff;
	y = (flags->img->height - 1) * (yd < 0);
	while (y + yd < (int)flags->img->height && y + yd >= 0)
	{
		x = (flags->img->width - 1) * (xd < 0);
		while (x + xd < (int)flags->img->width && x + xd >= 0)
		{
			flags->iterationcount[y][x] = flags->iterationcount[y + yd][x + xd];
			flags->pixelcount_i[flags->iterationcount[y][x]]++;
			if (xd < 0)
				x--;
			else
				x++;
		}
		if (yd < 0)
			y--;
		else
			y++;
	}
}

void	update_image(t_flags *flags)
{
	int	i;

	i = 0;
	while ((int)i < flags->max_iter)
		flags->pixelcount_i[i++] = 0;
	if (flags->update)
	{
		flags->x_diff = 0;
		flags->y_diff = 0;
	}
	else if (flags->x_diff || flags->y_diff)
		copy_iterationcount(flags);
	fill_iterationcount(flags);
	i = 0;
	flags->total = 0;
	while (i < flags->max_iter)
		flags->total += flags->pixelcount_i[i++];
	color_image(flags);
}

int	main(int argc, char **argv)
{
	t_flags		flags;

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
