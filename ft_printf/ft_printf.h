/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:43:22 by padam             #+#    #+#             */
/*   Updated: 2023/10/13 22:54:31 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
	char	conversion;
	int		precision;
	int		hashtag;
	int		plus;
	int		space;
	int		min_width;
	int		minus;
	int		zero;
}	t_flags;

//cases
t_list	*character(int c);
t_list	*string(char *str);
t_list	*pointer(void *ptr);
t_list	*integer(long integer);

//lst_functions
void	*ctop(char c);
void	print_content(void *ptr);

#endif
