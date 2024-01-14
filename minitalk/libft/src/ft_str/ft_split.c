/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:17:41 by padam             #+#    #+#             */
/*   Updated: 2023/11/03 16:47:33 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	static int	iteration = 0;
	int			lettercount;
	char		**split_words;

	lettercount = 0;
	while (*s == c && *s)
		s++;
	while (s[lettercount] != c && s[lettercount])
		lettercount++;
	if (lettercount > 0 && ++iteration)
	{
		split_words = ft_split(s + lettercount, c);
		if (iteration-- && !split_words)
			return (NULL);
		split_words[iteration] = ft_substr(s, 0, lettercount);
		lettercount = 1;
		if (!split_words[iteration])
			while (split_words[iteration + lettercount])
				free(split_words[iteration + lettercount++]);
		if (!split_words[iteration])
			return (free(split_words), NULL);
	}
	else
		split_words = ft_calloc((iteration + 1), sizeof(char *));
	return (split_words);
}
