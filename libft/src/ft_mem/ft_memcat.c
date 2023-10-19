/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:22:25 by padam             #+#    #+#             */
/*   Updated: 2023/10/19 19:23:18 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
