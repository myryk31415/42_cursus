/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:30:10 by padam             #+#    #+#             */
/*   Updated: 2023/11/09 21:05:30 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define WIDTH 2000
# define HEIGHT 600

typedef struct s_flags
{
	int		height;
	int		width;
	double	x;
	double	y;
	double	zoom;
	int		max_iter;
	int		treshold;
}	t_flags;

//hooks
void	hook(void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);

//mandelbrot
int		mandelbrot_iterations(double x, double y, t_flags *flags);

#endif
