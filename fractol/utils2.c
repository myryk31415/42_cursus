/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:44 by padam             #+#    #+#             */
/*   Updated: 2024/03/29 22:17:27 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdint.h"

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
	ft_putstr_fd("Change julia parameters - WASD\n", 2);
	ft_putstr_fd("Reset - H\n", 2);
	ft_putstr_fd("Change color - C\n", 2);
	ft_putstr_fd("De/Increase max iterations - I/O\n", 2);
	ft_putstr_fd("Exit - ESC\n", 2);
	ft_putstr_fd("----------------------------------------\n", 2);
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
		if (argc > 2 && !ft_isnumber(argv[2]))
			return (0);
		else if (argc > 2)
			flags->julia_x = (float)ft_atoi(argv[2]) / 100;
		if (argc == 4 && !ft_isnumber(argv[3]))
			return (0);
		else if (argc == 4)
			flags->julia_y = (float)ft_atoi(argv[3]) / 100;
	}
	return (1);
}

static int	new_iterationcount(mlx_t *mlx, t_flags *flags)
{
	int	i;

	i = 0;
	flags->iterationcount = ft_calloc(mlx->height, sizeof(int *));
	if (!flags->iterationcount)
	{
		stop_program("Error: malloc for iterationcount failed\n", flags);
		return (0);
	}
	while (i < mlx->height)
	{
		flags->iterationcount[i] = ft_calloc(mlx->width, sizeof(int));
		if (!flags->iterationcount[i])
		{
			while (--i)
				free(flags->iterationcount[i]);
			free(flags->iterationcount);
			flags->iterationcount = NULL;
			stop_program("Error: malloc for iterationcount failed\n", flags);
			return (0);
		}
		i++;
	}
	return (1);
}

void	new_image(t_flags *flags)
{
	// uint32_t		i;
	mlx_t		*mlx;

	mlx = flags->mlx;
	if (flags->img)
		mlx_delete_image(mlx, flags->img);
	if (flags->iterationcount)
	{
		// i = 0;
		// while (i < flags->img->height)
		// 	free(flags->iterationcount[i++]);
		// free(flags->iterationcount);
	}
	flags->img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!flags->img)
	{
		stop_program("Error: mlx_new_image failed\n", flags);
		return ;
	}
	mlx_image_to_window(mlx, flags->img, 0, 0);
	if (!new_iterationcount(mlx, flags))
		return ;
	update_image(flags);
}
