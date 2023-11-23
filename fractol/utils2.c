/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:44 by padam             #+#    #+#             */
/*   Updated: 2023/11/23 15:24:08 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_parameters(void)
{
	ft_putstr_fd("----------------------------------------\n", 2);
	ft_putstr_fd("Usage: ./fractol \"fractal\" \"julia_x\" \"julia_y\" \n", 2);
	ft_putstr_fd("Available fractals: m - mandelbrot,\
 j - julia, b - burning ship\n", 2);
	ft_putstr_fd("Available julia parameters:\n", 2);
	ft_putstr_fd("julia_x - real part of the complex number\n", 2);
	ft_putstr_fd("julia_y - imaginary part of the complex number\n", 2);
	ft_putstr_fd("Both numbers will be divided by 100\n", 2);
	ft_putstr_fd("Example: ./fractol j 10 -30\n", 2);
	ft_putstr_fd("----------------------------------------\n", 2);
	ft_putstr_fd("Controls:\n", 2);
	ft_putstr_fd("Zoom - scroll wheel\n", 2);
	ft_putstr_fd("Move - arrow keys\n", 2);
	ft_putstr_fd("Change julia parameters - ASDW\n", 2);
	ft_putstr_fd("Reset - H\n", 2);
	ft_putstr_fd("Change color - C\n", 2);
	ft_putstr_fd("In/Decrease max iterations - I/O\n", 2);
	ft_putstr_fd("Exit - ESC\n", 2);
	ft_putstr_fd("----------------------------------------\n", 2);
}

static int	isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_parameters(int argc, char **argv, t_flags *flags)
{
	if (argc < 2 || argc > 4)
		return (0);
	if (ft_strchr("jmb", argv[1][0]) && argv[1][1] == 0)
		flags->fractal = argv[1][0];
	else
		return (0);
	if (flags->fractal != 'j' && argc > 2)
		return (0);
	if (flags->fractal == 'j')
	{
		flags->julia_x = 0;
		flags->julia_y = 0;
		if (argc > 2 && !isnumber(argv[2]))
			return (0);
		else if (argc > 2)
			flags->julia_x = (float)ft_atoi(argv[2]) / 100;
		if (argc == 4 && !isnumber(argv[3]))
			return (0);
		else if (argc == 4)
			flags->julia_y = (float)ft_atoi(argv[3]) / 100;
	}
	return (1);
}
