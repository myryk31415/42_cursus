/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by padam             #+#    #+#             */
/*   Updated: 2024/03/29 22:20:55 by padam            ###   ########.fr       */
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

void	set_color(int pixel, uint32_t color, t_flags *flags)
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
	flags->max_iter = 100;
	flags->pixelcount_i = ft_calloc(flags->max_iter + 1, sizeof(int));
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
	flags->treshold = 4;
	flags->update = 1;
	flags->error = 0;
	return (1);
}

void	*stop_program(char *message, t_flags *flags)
{
	uint32_t	i;

	ft_putstr_fd(message, 2);
	flags->error = 1;
	if (flags->iterationcount)
	{
		i = 0;
		while (i < flags->img->height)
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
