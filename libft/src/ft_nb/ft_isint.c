/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:40:41 by padam             #+#    #+#             */
/*   Updated: 2023/12/17 19:55:29 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	long	i;
	int		negative;

	i = 0;
	negative = 0;
	if (!ft_isnumber(str) || ft_strlen(str) > 11)
		return (0);
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	if (negative)
		i *= -1;
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}
