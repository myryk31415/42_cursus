/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:25:28 by padam             #+#    #+#             */
/*   Updated: 2023/10/10 16:21:57 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s);
	while (ft_strchr(set, s[start]) && *set && *s)
		start++;
	while (ft_strchr(set, s[end]) && *set && *s)
		end--;
	return (ft_substr((s), start, end - start + 1));
}
