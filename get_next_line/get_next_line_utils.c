/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:51:51 by padam             #+#    #+#             */
/*   Updated: 2023/10/27 13:24:58 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = '\0';
		s++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
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

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_calloc(sizeof (char), ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
