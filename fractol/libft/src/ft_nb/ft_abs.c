/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:23:47 by padam             #+#    #+#             */
/*   Updated: 2023/11/23 16:46:47 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long	ft_abs_long(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	ft_abs_double(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
