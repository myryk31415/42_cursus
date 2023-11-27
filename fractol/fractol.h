/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:30:10 by padam             #+#    #+#             */
/*   Updated: 2023/11/24 17:52:59 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1800
# define HEIGHT 1000

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BORDER 0xFFFF00

typedef struct s_flags
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		fractal;
	int			update;
	int			error;
	double		julia_x;
	double		julia_y;
	double		x;
	double		x_diff;
	double		y;
	double		y_diff;
	double		zoom;
	int			color;
	int			max_iter;
	int			treshold;
	int			**iterationcount;
	int			*pixelcount_i;
	int			total;
}	t_flags;

void	update_image(t_flags *flags);

//utils
int		get_color(double hue, t_flags *flags);
void	set_color(int pixel, u_int32_t color, t_flags *flags);
int		initialize_flags(t_flags *flags);
void	*stop_program(char *message, t_flags *flags);
void	new_image(t_flags *flags);

void	put_parameters(void);
int		check_parameters(int argc, char **argv, t_flags *flags);

//hooks
void	hook(void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);

//fractals
int		get_iteration(int x, int y, t_flags *flags);

#endif
