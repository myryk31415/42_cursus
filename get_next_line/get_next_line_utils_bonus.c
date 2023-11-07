/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:51:51 by padam             #+#    #+#             */
/*   Updated: 2023/10/29 13:10:36 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr)
	{
		while (i < size)
		{
			*(char *)ptr = '\0';
			ptr++;
			i++;
		}
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		l;
	size_t	i;

	i = 0;
	l = ft_strlen(src);
	while (*src && i + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (l);
}
