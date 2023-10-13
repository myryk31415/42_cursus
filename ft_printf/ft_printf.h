/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:43:22 by padam             #+#    #+#             */
/*   Updated: 2023/10/13 14:52:21 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
	int	precision;
	int	hashtag;
	int	plus;
	int	space;
	int	min_width;
	int	minus;
	int	zero;
}	t_flags;

#endif
