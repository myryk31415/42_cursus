/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:30:10 by padam             #+#    #+#             */
/*   Updated: 2023/11/10 16:29:08 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 1800
# define HEIGHT 1000

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

typedef struct s_flags
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	// int			height;
	// int			width;
	double		x;
	double		y;
	double		zoom;
	int			max_iter;
	int			treshold;
}	t_flags;

//utils
void	set_color(int pixel, u_int32_t color, u_int8_t dimm, t_flags *flags);
void	initialize_flags(t_flags *flags);
void	put_parameters(void);

//hooks
void	hook(void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);

//mandelbrot
int		mandelbrot_iterations(double x, double y, t_flags *flags);

#endif
