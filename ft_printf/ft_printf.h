/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:43:22 by padam             #+#    #+#             */
/*   Updated: 2023/10/14 17:27:25 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"

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

typedef struct s_listchar
{
	char				content;
	struct s_listchar	*next;
}	t_listchar;

int	ft_printf(const char *str, ...);

//cases
t_listchar	*character(int c);
t_listchar	*string(char *str, int precision);
t_listchar	*pointer(void *ptr);
t_listchar	*integer(long integer, int precision);

//lst_functions
void		print_content(char c);
t_listchar	*ft_lstcharnew(char c);
int			ft_lstcharsize(t_listchar *lst);
t_listchar	*ft_lstcharlast(t_listchar *lst);
void		ft_lstcharadd_back(t_listchar **lst, t_listchar *new);
void		ft_lstcharadd_front(t_listchar **lst, t_listchar *new);
void		ft_lstchariter(t_listchar *lst, void (*f)(char));
void		ft_lstcharclear(t_listchar **lst);

#endif
