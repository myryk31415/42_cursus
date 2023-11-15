/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by padam             #+#    #+#             */
/*   Updated: 2023/11/16 00:19:44 by padam            ###   ########.fr       */
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

int	initialize_flags(t_flags *flags)
{
	flags->mlx = mlx_init(WIDTH, HEIGHT, "fract\'ol", true);
	if (!flags->mlx)
		return (0);
	flags->pixelcount_i = ft_calloc(MAX_ITER + 1, sizeof(int));
	if (!flags->pixelcount_i)
	{
		stop_program("Error: malloc failed\n", flags);
		return (0);
	}
	new_image(flags);
	flags->julia_x = 0;
	flags->julia_y = 0;
	// flags->height = HEIGHT;
	// flags->width = WIDTH;
	flags->x = 0;
	flags->y = 0;
	flags->zoom = 400;
	flags->zoom_old = 400;
	flags->max_iter = MAX_ITER;
	flags->treshold = 4;
	flags->update = 1;
	flags->error = 0;
	return (1);
}

void	put_parameters(void)
{
	ft_putstr_fd("Usage: ./fractol \"fractal\" \"julia_x\" \"julia_y\" \n", 2);
	ft_putstr_fd("Available fractals: m - mandelbrot, j - julia, b - burning ship\n", 2);
	ft_putstr_fd("Available julia parameters:\n", 2);
	ft_putstr_fd("julia_x - real part of the complex number\n", 2);
	ft_putstr_fd("julia_y - imaginary part of the complex number\n", 2);
	ft_putstr_fd("Both numbers will be divided by 100\n", 2);
}

void	*stop_program(char *message, t_flags *flags)
{
	int	i;

	ft_putstr_fd(message, 2);
	flags->error = 1;
	if (flags->iterationcount)
	{
		i = 0;
		while ((u_int32_t)i < flags->img->height)
			free(flags->iterationcount[i++]);
		free(flags->iterationcount);
		flags->iterationcount = NULL;
	}
	if (flags->pixelcount_i)
	{
		free(flags->pixelcount_i);
		flags->pixelcount_i = NULL;
	}
	mlx_close_window(flags->mlx);
	return (NULL);
}

void	reset_flags_arrays(t_flags *flags)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < flags->img->height)
	{
		j = 0;
		while (j < flags->img->width)
			flags->iterationcount[i][j++] = 0;
		i++;
	}
	i = 0;
	while ((int)i < flags->max_iter)
		flags->pixelcount_i[i++] = 0;
}

void	new_image(t_flags *flags)
{
	int32_t		i;
	mlx_t		*mlx;

	mlx = flags->mlx;
	if (flags->img)
		mlx_delete_image(mlx, flags->img);
	if (flags->iterationcount)
	{
		i = 0;
		while ((u_int32_t)i < flags->img->height)
			free(flags->iterationcount[i++]);
		free(flags->iterationcount);
	}
	flags->img = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, flags->img, 0, 0);
	i = 0;
	flags->iterationcount = ft_calloc(mlx->height, sizeof(int *));
	if (!flags->iterationcount)
	{
		stop_program("Error: malloc failed\n", flags);
		return ;
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
			stop_program("Error: malloc failed\n", flags);
			return ;
		}
		i++;
	}
	update_image(flags);
}
