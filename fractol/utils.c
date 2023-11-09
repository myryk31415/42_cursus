/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by padam             #+#    #+#             */
/*   Updated: 2023/11/09 21:01:40 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_parameters(void)
{
	ft_putstr_fd("Usage: ./fractol \"fractal\"\n", 2);
	ft_putstr_fd("Available fractals:\n", 2);
	ft_putstr_fd("  - Mandelbrot\n", 2);
	ft_putstr_fd("  - Julia\n", 2);
	ft_putstr_fd("  - Burning Ship\n", 2);
	ft_putstr_fd("  - Tricorn\n", 2);
	ft_putstr_fd("  - Buffalo\n", 2);
	ft_putstr_fd("  - Mandelbar\n", 2);
	ft_putstr_fd("  - Celtic Mandelbrot\n", 2);
	ft_putstr_fd("  - Celtic Mandelbar\n", 2);
	ft_putstr_fd("  - Celtic Perpendicular\n", 2);
	ft_putstr_fd("  - Perpendicular Mandelbrot\n", 2);
	ft_putstr_fd("  - Perpendicular Burning Ship\n", 2);
	ft_putstr_fd("  - Perpendicular Buffalo\n", 2);
	ft_putstr_fd("  - Perpendicular Tricorn\n", 2);
	ft_putstr_fd("  - Perpendicular Burning Julia\n", 2);
	ft_putstr_fd("  - Perpendicular Celtic\n", 2);
	ft_putstr_fd("  - Perpendicular Celtic Mandelbar\n", 2);
}
