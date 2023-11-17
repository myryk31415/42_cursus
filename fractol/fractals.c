/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:37:08 by padam             #+#    #+#             */
/*   Updated: 2023/11/17 15:36:35 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	check_periodicity(double x, double y, int reset)
// {
// 	static int	periodicity[2] = {0, 0};
// 	static int	i = 0;

// 	if (reset == 1)
// 		i = -1;
// 	else
// 	{
// 		if (i == -1)
// 		{
// 			periodicity[0] = (int)x;
// 			periodicity[1] = (int)y;
// 		}
// 		else
// 		{
// 			if (periodicity[0] == (int)x && periodicity[1] == (int)y)
// 				return (1);
// 			if (i++ > 20)
// 			{
// 				i = 0;
// 				periodicity[0] = (int)x;
// 				periodicity[1] = (int)y;
// 			}
// 		}
// 	}
// 	return (0);
// }

// int	mandelbrot_iterations(double x0, double y0, t_flags *flags)
// {
// 	int		i;
// 	double	x1;
// 	double	y1;
// 	double	x2;
// 	double	y2;

// 	i = 0;
// 	x1 = 0;
// 	y1 = 0;
// 	x2 = 0;
// 	y2 = 0;
// 	while (x2 + y2 < flags->treshold && ++i < flags->max_iter)
// 	{
// 		y1 = (x1 + x1) * y1 + y0;
// 		x1 = x2 - y2 + x0;
// 		y2 = y1 * y1;
// 		x2 = x1 * x1;
// 	}
// 	return (i);
// }

int	burningship_iterations(double x0, double y0, t_flags *flags)
{
	int		i;
	int		j;
	double	x_old;
	double	y_old;
	double	*coords;

	i = 0;
	j = 0;
	coords = (double [4]){0, 0, 0, 0};
	while (coords[2] + coords[3] < flags->treshold && ++i < flags->max_iter)
	{
		if (!j--)
		{
			j = flags->max_iter / 100;
			x_old = coords[0];
			y_old = coords[1];
		}
		coords[1] = (coords[0] + coords[0]) * coords[1];
		coords[1] = coords[1] * (1 - 2 * (coords[1] < 0)) + y0;
		coords[0] = coords[2] - coords[3] + x0;
		if (coords[0] == x_old && coords[1] == y_old)
			return (flags->max_iter);
		coords[3] = coords[1] * coords[1];
		coords[2] = coords[0] * coords[0];
	}
	return (i);
}

int	mandelbrot_iterations(double x0, double y0, t_flags *flags)
{
	int		i;
	int		j;
	double	x_old;
	double	y_old;
	double	*coords;

	i = 0;
	j = 0;
	coords = (double [4]){0, 0, 0, 0};
	while (coords[2] + coords[3] < flags->treshold && ++i < flags->max_iter)
	{
		if (!j--)
		{
			j = flags->max_iter / 100;
			x_old = coords[0];
			y_old = coords[1];
		}
		coords[1] = (coords[0] + coords[0]) * coords[1] + y0;
		coords[0] = coords[2] - coords[3] + x0;
		if (coords[0] == x_old && coords[1] == y_old)
			return (flags->max_iter);
		coords[3] = coords[1] * coords[1];
		coords[2] = coords[0] * coords[0];
	}
	return (i);
}

int	julia_iterations(double x_old, double y_old, t_flags *flags)
{
	int		i;
	int		j;
	double	*coords;

	i = 0;
	j = flags->max_iter / 100;
	coords = (double [4]){0, 0, 0, 0};
	coords[0] = x_old;
	coords[1] = y_old;
	while (coords[2] + coords[3] < flags->treshold && ++i < flags->max_iter)
	{
		coords[3] = coords[1] * coords[1];
		coords[2] = coords[0] * coords[0];
		coords[1] = (coords[0] + coords[0]) * coords[1] + flags->julia_y;
		coords[0] = coords[2] - coords[3] + flags->julia_x;
		if (coords[0] == x_old && coords[1] == y_old)
			return (flags->max_iter);
		if (j++ > flags->max_iter / 100)
		{
			j = 0;
			x_old = coords[0];
			y_old = coords[1];
		}
	}
	return (i);
}

int	get_iteration(int x, int y, t_flags *flags)
{
	double		x1;
	double		y1;
	int			i;

	i = 0;
	// if (flags->iterationcount[y][x] != 0)
	// 	return (flags->iterationcount[y][x]);
	x1 = (x - (int)(flags->img->width) / 2) / flags->zoom + flags->x;
	y1 = (y - (int)(flags->img->height) / 2) / flags->zoom + flags->y;
	// if (flags->iterationcount[y][x] == MAX_ITER)
	// 	bordertrace(x , y, flags);
	if (flags->fractal == 'm')
		i = mandelbrot_iterations(x1, y1, flags);
	else if (flags->fractal == 'j')
		i = julia_iterations(x1, y1, flags);
	else if (flags->fractal == 'b')
		i = burningship_iterations(x1, y1, flags);
	flags->iterationcount[y][x] = i;
	return (i);
}
