/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:20:42 by padam             #+#    #+#             */
/*   Updated: 2023/10/15 22:58:29 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static char	*skip_number(char *str)
{
	while (ft_isdigit(*str))
		str++;
	str--;
	return (str);
}

static t_listchar	*use_flags(t_listchar *lst, t_flags *flags)
{
	if (flags->conversion == 'p')
	{
		if (!ft_lstcharadd_front(&lst, ft_lstcharnew('x'))
			|| !ft_lstcharadd_front(&lst, ft_lstcharnew('0')))
			return (ft_lstcharclear(&lst));
	}
	if (flags->conversion == 'X')
	{
		ft_lstchariter(lst, ft_toupperchar);
	}
	return (lst);
}


static void	read_flags(char *str, t_flags *flags)
{
	flags->precision = -1;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->min_width = 0;
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

static int	handle(va_list args, t_flags *flags)
{
	t_listchar	*output;
	int			count;

	if (flags->conversion == 'c')
		output = character((unsigned char)va_arg(args, int));
	if (flags->conversion == 's')
		output = string(va_arg(args, char *), flags);
	if (flags->conversion == 'p')
		output = pointer((unsigned long)va_arg(args, void *), flags);
	if (flags->conversion == 'd')
		output = integer((long)va_arg(args, int), flags);
	if (flags->conversion == 'i')
		output = integer((long)va_arg(args, int), flags);
	if (flags->conversion == 'u')
		output = integer((long)va_arg(args, unsigned int), flags);
	if (ft_strchr("xX", flags->conversion))
		output = integer((long)va_arg(args, unsigned int), flags);
	if (flags->conversion == '%')
		output = ft_lstcharnew('%');
	if (!output)
		return (0);
	output = use_flags(output, flags);
	ft_lstchariter(output, print_content);
	count = ft_lstcharsize(output);
	ft_lstcharclear(&output);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar_fd(*str++, 1);
			count++;
		}
		if (*str)
		{
			read_flags((char *)++str, &flags);
			count += handle(args, &flags);
			while (!ft_strchr("cspdiuxX%", *str))
				str++;
			str++;
		}
	}
	return (count);
}
