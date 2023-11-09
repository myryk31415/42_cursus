/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:37:08 by padam             #+#    #+#             */
/*   Updated: 2023/11/09 20:59:19 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(double x, double y, t_flags *flags)
{
	int		i;
	double	c;
	double	z;

	c = sqrt(x * x + y * y);
	while (z <= flags->treshold && i < flags->max_iter)
		z = z * z + c;
	return (i);
}
