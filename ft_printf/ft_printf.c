/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:20:42 by padam             #+#    #+#             */
/*   Updated: 2023/10/18 18:30:59 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static t_listchar	*min_width(t_listchar *lst, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->zero && (flags->negative || flags->plus || flags->space)
		&& flags->conversion != '%')
		i++;
	if (flags->hashtag && flags->zero && flags->conversion != '%')
		i += 2;
	while (i < flags->min_width - ft_lstcharsize(lst))
	{
		if (flags->minus)
		{
			if (!ft_lstcharadd_back(&lst, ft_lstcharnew(' ', flags)))
				return (ft_lstcharclear(&lst));
		}
		else if (flags->zero)
		{
			if (!ft_lstcharadd_front(&lst, ft_lstcharnew('0', flags)))
				return (ft_lstcharclear(&lst));
		}
		else
			if (!ft_lstcharadd_front(&lst, ft_lstcharnew(' ', flags)))
				return (ft_lstcharclear(&lst));
	}
	return (lst);
}

static t_listchar	*use_flags(t_listchar *lst, t_flags *flags)
{
	char	c;

	c = flags->conversion;
	if (flags->precision >= 0)
		flags->zero = 0;
	if (flags->conversion == 'X')
		ft_lstchariter(lst, ft_toupperchar, flags);
	if (flags->zero)
		lst = min_width(lst, flags);
	if ((ft_strchr("xX", c) && flags->hashtag) || c == 'p')
		lst = add_prefix(lst, flags);
	if (flags->negative
		&& !ft_lstcharadd_front(&lst, ft_lstcharnew('-', flags)))
		return (ft_lstcharclear(&lst));
	if (flags->plus && ft_strchr("di", c) && !flags->negative)
		if (!ft_lstcharadd_front(&lst, ft_lstcharnew('+', flags)))
			return (ft_lstcharclear(&lst));
	if (!flags->plus && flags->space
		&& ft_strchr("di", c) && !flags->negative)
		if (!ft_lstcharadd_front(&lst, ft_lstcharnew(' ', flags)))
			return (ft_lstcharclear(&lst));
	if (!flags->zero)
		lst = min_width(lst, flags);
	return (lst);
}

static void	read_flags(char *str, t_flags *flags)
{
	while (!ft_strchr("cspdiuxX%", *str))
	{
		if (*str == '.')
		{
			flags->precision = ft_atoi(++str);
			str = skip_number(str);
		}
		else if (*str == '#')
			flags->hashtag = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '-')
			flags->minus = 1;
		else if (*str == '0')
			flags->zero = 1;
		else if (ft_isdigit(*str))
		{
			flags->min_width = ft_atoi(str);
			str = skip_number(str);
		}
		str++;
	}
	flags->conversion = *str;
}

static int	handle_type(va_list args, t_flags *flags)
{
	t_listchar	*output;

	if (flags->conversion == '%')
		output = ft_lstcharnew('%', flags);
	if (flags->conversion == 'c')
		output = character((unsigned char)va_arg(args, int), flags);
	if (flags->conversion == 's')
		output = string(va_arg(args, char *), flags);
	if (flags->conversion == 'p')
		output = pointer((unsigned long)va_arg(args, void *), flags);
	if (ft_strchr("di", flags->conversion))
		output = integer((long long)va_arg(args, int), flags);
	if (ft_strchr("xXu", flags->conversion))
		output = integer((long long)va_arg(args, unsigned int), flags);
	if (!flags->error)
		output = use_flags(output, flags);
	if (!flags->error)
		ft_lstchariter(output, print_content, flags);
	ft_lstcharclear(&output);
	return (flags->count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;

	flags.count = 0;
	flags.error = 0;
	va_start(args, str);
	while (*str && !flags.error)
	{
		while (*str != '%' && *str && !flags.error)
			print_content((unsigned char *)str++, &flags);
		if (*str && !flags.error)
		{
			reset_flags(&flags);
			read_flags((char *)++str, &flags);
			handle_type(args, &flags);
			while (!ft_strchr("cspdiuxX%", *str))
				str++;
			str++;
		}
	}
	va_end(args);
	if (flags.error)
		return (-1);
	return (flags.count);
}
