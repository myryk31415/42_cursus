/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:24:35 by padam             #+#    #+#             */
/*   Updated: 2024/01/02 22:37:39 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_listchar	*character(int c, t_flags *flags)
{
	return (ft_lstcharnew(c, flags));
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
		if (!ft_lstcharadd_back(&lst,
				ft_lstcharnew(*(unsigned char *)str++, flags)))
			return (ft_lstcharclear(&lst));
	return (lst);
}

t_listchar	*integer(long long i, t_flags *flags)
{
	t_listchar	*lst;
	int			j;
	int			base;

	if (i == 0)
		flags->hashtag = 0;
	if (i == 0 && flags->precision < 0)
		return (ft_lstcharnew('0', flags));
	base = 10 + 6 * (ft_strchr("xX", flags->conversion) != NULL);
	j = 0;
	lst = NULL;
	flags->negative = (i < 0);
	i -= 2 * i * (i < 0);
	while (i && ++j)
	{
		if (!ft_lstcharadd_front(&lst,
				ft_lstcharnew("0123456789abcdef"[i % base], flags)))
			return (ft_lstcharclear(&lst));
		i /= base;
	}
	while (j++ < flags->precision)
		if (!ft_lstcharadd_front(&lst, ft_lstcharnew('0', flags)))
			return (ft_lstcharclear(&lst));
	return (lst);
}

t_listchar	*pointer(unsigned long i, t_flags *flags)
{
	t_listchar	*lst;

	if (!i && flags->precision < 0)
	{
		flags->conversion = 's';
		return (string("0x0", flags));
	}
	lst = NULL;
	while (i)
	{
		if (!ft_lstcharadd_front(&lst,
				ft_lstcharnew("0123456789abcdef"[i % 16], flags)))
			return (ft_lstcharclear(&lst));
		i /= 16;
	}
	return (lst);
}
