/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:20:42 by padam             #+#    #+#             */
/*   Updated: 2023/10/13 23:01:16 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static char	*skip_number(char *str)
{
	while (ft_isdigit(*str))
		str++;
	str--;
	return (str);
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
	t_list	*output;
	int		count;

	if (flags->conversion == 'c')
		output = character((unsigned char)va_arg(args, int));
	if (flags->conversion == 's')
		output = string(va_arg(args, char *));
	if (flags->conversion == 'p')
		output = pointer(va_arg(args, void *));
	if (flags->conversion == 'd')
		output = integer((long)va_arg(args, int));
	if (flags->conversion == 'i')
		output = integer((long)va_arg(args, int));
	if (flags->conversion == 'u')
		output = integer((long)va_arg(args, unsigned int));
	if (ft_strchr("xX", flags->conversion))
		output = integer((long)va_arg(args, unsigned int));
	if (flags->conversion == '%')
		output = ft_lstnew(ctop('%'));
	if (!output)
		return (NULL);
	ft_lstiter(output, print_content);
	count = ft_lstsize(output);
	ft_lstclear(output, free);
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
		while (*str != '%')
		{
			ft_putchar_fd(*str++, 1);
			count++;
		}
		read_flags((char *)str, &flags);
		count += handle(args, &flags);
	}
	return (count);
}
