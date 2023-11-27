/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:42:45 by padam             #+#    #+#             */
/*   Updated: 2023/10/19 13:35:51 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	ptr = dst;
	if (!dst && !src)
		return (dst);
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		src++;
		dst++;
	}
	return (ptr);
}
