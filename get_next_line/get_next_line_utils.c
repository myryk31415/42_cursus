/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:51:51 by padam             #+#    #+#             */
/*   Updated: 2023/10/19 18:18:30 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
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
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = ft_strlen(dst);
	if (l < dstsize)
	{
		ft_strlcpy((dst + l), src, dstsize - l);
		return (l + ft_strlen(src));
	}
	return (ft_strlen(src) + dstsize);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*joint;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	joint = malloc(l * sizeof(char));
	if (!joint)
		return (NULL);
	ft_strlcpy(joint, s1, l);
	ft_strlcat(joint, s2, l);
	return (joint);
}
