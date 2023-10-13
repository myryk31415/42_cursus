/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:20:42 by padam             #+#    #+#             */
/*   Updated: 2023/10/13 15:35:37 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static void	read_flags(char *str, t_flags *flags)
{
	flags->precision = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->min_width = 0;
	while (!ft_strchr("cspdiuxX%", *str))
	{
		if (*str == '.')
			flags->precision = 1;
		if (*str == '#')
			flags->hashtag = 1;
		if (*str == '+')
			flags->plus = 1;
		if (*str == ' ')
			flags->space = 1;
		if (*str == '-')
			flags->minus = 1;
		if (*str == '0')
			flags->zero = 1;
		else if (ft_isdigit(*str))
		{
			flags->min_width = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		str++;
	}
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
		while (*str != '%')
		{
			ft_putchar_fd(*str++, 1);
			count++;
		}
		read_flags(str, &flags);
	}
	return (count);
}
