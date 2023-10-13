/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:45:42 by padam             #+#    #+#             */
/*   Updated: 2023/10/10 19:07:15 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
