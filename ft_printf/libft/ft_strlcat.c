/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:07:51 by padam             #+#    #+#             */
/*   Updated: 2023/10/11 18:07:43 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
