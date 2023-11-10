/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by padam             #+#    #+#             */
/*   Updated: 2023/11/10 16:29:22 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//rgb
void	set_color(int pixel, u_int32_t color, u_int8_t dimm, t_flags *flags)
{
	pixel *= 4;
	flags->img->pixels[pixel] = ((color >> 16) - dimm);
	flags->img->pixels[pixel + 1] = ((color >> 8) - dimm) & 0xFF;
	flags->img->pixels[pixel + 2] = (color - dimm) & 0xFF;
	flags->img->pixels[pixel + 3] = 0xFF;
}

void	initialize_flags(t_flags *flags)
{
	// flags->height = HEIGHT;
	// flags->width = WIDTH;
	flags->x = 0;
	flags->y = 0;
	flags->zoom = 400;
	flags->max_iter = 500;
	flags->treshold = 2;
}

void	put_parameters(void)
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
