/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:34:55 by padam             #+#    #+#             */
/*   Updated: 2023/10/10 14:19:32 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	bytes;

	bytes = (n <= 0);
	while (n)
	{
		n /= 10;
		bytes++;
	}
	return (bytes);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	num;
	int		l;

	num = n;
	l = count_digits(num);
	ptr = malloc(l + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[l] = '\0';
	if (num < 0)
	{
		num *= -1;
		ptr[0] = '-';
	}
	if (num == 0)
		ptr[0] = '0';
	while (num)
	{
		ptr[--l] = '0' + num % 10;
		num /= 10;
	}
	return (ptr);
}
