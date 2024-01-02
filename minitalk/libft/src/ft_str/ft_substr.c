/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:48:08 by padam             #+#    #+#             */
/*   Updated: 2023/10/10 14:40:27 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (ft_strlen(src) < len)
		ptr = malloc(sizeof (char) * (ft_strlen(src) + 1));
	else
		ptr = malloc(sizeof (char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (src[i] && i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	return (ft_strndup(s + start, len));
}
