/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by padam             #+#    #+#             */
/*   Updated: 2023/11/23 14:25:41 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(double hue, t_flags *flags)
{
	int	i;

	i = hue * hue * hue * hue * 255;
	i *= flags->color;
	return (i);
}

void	set_color(int pixel, u_int32_t color, t_flags *flags)
{
	pixel *= 4;
	flags->img->pixels[pixel] = color >> 16 & 0xFF;
	flags->img->pixels[pixel + 1] = color >> 8 & 0xFF;
	flags->img->pixels[pixel + 2] = color & 0xFF;
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
	flags->x = 0;
	flags->y = 0;
	flags->zoom = 400;
	flags->color = 1;
	flags->max_iter = MAX_ITER;
	flags->treshold = 4;
	flags->update = 1;
	flags->error = 0;
	return (1);
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
	if (!flags->img)
	{
		stop_program("Error: mlx_new_image failed\n", flags);
		return ;
	}
	mlx_image_to_window(mlx, flags->img, 0, 0);
	i = 0;
	flags->iterationcount = ft_calloc(mlx->height, sizeof(int *));
	if (!flags->iterationcount)
	{
		stop_program("Error: malloc for iterationcount failed\n", flags);
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
			stop_program("Error: malloc for iterationcount failed\n", flags);
			return ;
		}
		i++;
	}
	update_image(flags);
}
