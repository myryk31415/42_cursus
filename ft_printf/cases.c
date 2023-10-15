/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:24:35 by padam             #+#    #+#             */
/*   Updated: 2023/10/15 23:14:24 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_listchar	*character(int c)
{
	return (ft_lstcharnew(c));
}

t_listchar	*string(char *str, t_flags *flags)
{
	t_listchar	*lst;
	int			i;

	if (!str)
		str = "(null)";
	lst = NULL;
	i = 0;
	while (*str && (i++ < flags->precision || flags->precision < 0))
	{
		if (!ft_lstcharadd_back(&lst, ft_lstcharnew(*(unsigned char *)str++)))
			return (ft_lstcharclear(&lst));
	}
	return (lst);
}

t_listchar	*integer(long long i, t_flags *flags)
{
	t_listchar	*lst;
	int			j;
	int			negative;
	int			base;

	base = 10 + 6 * (0 < ft_strchr("xXp", flags->conversion));
	j = 0;
	lst = NULL;
	negative = (i < 0);
	i += -2 * i * (i < 0);
	while (i && ++j)
	{
		if (!ft_lstcharadd_front(&lst,
				ft_lstcharnew("0123456789abcdef"[i % base])))
			return (ft_lstcharclear(&lst));
		i /= base;
	}
	while (j++ < flags->precision)
	{
		if (!ft_lstcharadd_front(&lst, ft_lstcharnew('0')))
			return (ft_lstcharclear(&lst));
	}
	if (negative && !ft_lstcharadd_front(&lst, ft_lstcharnew('-')))
		return (ft_lstcharclear(&lst));
	return (lst);
}

t_listchar	*pointer(unsigned long i, t_flags *flags)
{
	t_listchar	*lst;
	int			base;

	base = 10 + 6 * (0 < ft_strchr("xXp", flags->conversion));
	lst = NULL;
	i += -2 * i * (i < 0);
	while (i)
	{
		if (!ft_lstcharadd_front(&lst,
				ft_lstcharnew("0123456789abcdef"[i % base])))
			return (ft_lstcharclear(&lst));
		i /= base;
	}
	return (lst);
}
