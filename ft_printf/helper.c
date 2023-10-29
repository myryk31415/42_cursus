/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:27:33 by padam             #+#    #+#             */
/*   Updated: 2023/10/24 15:57:11 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

void	reset_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->min_width = 0;
	flags->negative = 0;
}

void	ft_toupperchar(unsigned char *c, t_flags *flags)
{
	flags->error += 0;
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}

void	print_content(unsigned char *c, t_flags *flags)
{
	if (write(1, c, 1) == -1)
		flags->error = 1;
	flags->count++;
}

char	*skip_number(char *str)
{
	while (ft_isdigit(*str))
		str++;
	str--;
	return (str);
}

t_listchar	*add_prefix(t_listchar *lst, t_flags *flags)
{
	char	c;

	c = flags->conversion;
	if (c == 'X' && !ft_lstcharadd_front(&lst, ft_lstcharnew('X', flags)))
		return (ft_lstcharclear(&lst));
	if (ft_strchr("xp", c)
		&& !ft_lstcharadd_front(&lst, ft_lstcharnew('x', flags)))
		return (ft_lstcharclear(&lst));
	if (!ft_lstcharadd_front(&lst, ft_lstcharnew('0', flags)))
		return (ft_lstcharclear(&lst));
	return (lst);
}
