/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:37:08 by padam             #+#    #+#             */
/*   Updated: 2023/11/10 15:00:04 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(double x, double y, t_flags *flags)
{
	int		i;
	double	x1;
	double	y1;
	double	x_tmp;

	i = 0;
	x1 = 0;
	y1 = 0;
	while (sqrt(x1 * x1 + y1 * y1) < flags->treshold && i++ < flags->max_iter)
	{
		x_tmp = x1 * x1 - y1 * y1 + x;
		y1 = 2 * x1 * y1 + y;
		x1 = x_tmp;
	}
	return (i);
}
