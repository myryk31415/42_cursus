/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:37:08 by padam             #+#    #+#             */
/*   Updated: 2023/11/23 14:35:13 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	j = 0;
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
		if (!j--)
		{
			j = flags->max_iter / 100;
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
	x1 = (x - (int)(flags->img->width) / 2) / flags->zoom + flags->x;
	y1 = (y - (int)(flags->img->height) / 2) / flags->zoom + flags->y;
	if (flags->fractal == 'm')
		i = mandelbrot_iterations(x1, y1, flags);
	else if (flags->fractal == 'j')
		i = julia_iterations(x1, y1, flags);
	else if (flags->fractal == 'b')
		i = burningship_iterations(x1, y1, flags);
	flags->iterationcount[y][x] = i;
	return (i);
}
