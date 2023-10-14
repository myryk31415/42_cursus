/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:24:35 by padam             #+#    #+#             */
/*   Updated: 2023/10/14 17:02:56 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_listchar	*character(int c)
{
	return (ft_lstcharnew(c));
}

t_listchar	*string(char *str, int precision)
{
	t_listchar	**lst;
	t_listchar	*new;
	int			i;

	i = 0;
	lst = NULL;
	while (*str && (i++ < precision || precision < 0))
	{
		new = ft_lstcharnew(*str);
		if (!new)
		{
			ft_lstcharclear(lst);
			return (NULL);
		}
		ft_lstcharadd_back(lst, new);
	}
	return (*lst);
}

t_listchar	*pointer(void *ptr)
{
	ptr = NULL;
	return (0);
}

t_listchar	*integer(long integer, int precision)
{
	t_listchar	**lst;
	t_listchar	*new;
	int			i;
	int			negative;

	i = 0;
	lst = NULL;
	negative = (integer < 0);
	while (integer || i++ < precision || negative)
	{
		if (integer)
			new = ft_lstcharnew('0' + integer % 10);
		else if (i - 1 < precision)
			new = ft_lstcharnew('0');
		else if (negative--)
			new = ft_lstcharnew('-');
		if (!new)
		{
			ft_lstcharclear(lst);
			return (NULL);
		}
		ft_lstcharadd_front(lst, new);
		integer /= 10;
	}
	return (0);
}
