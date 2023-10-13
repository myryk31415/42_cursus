/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:17:41 by padam             #+#    #+#             */
/*   Updated: 2023/10/11 13:36:13 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_letters(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static int	count_words(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static void	*clean(char **arr, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	int		lettercount;
	char	**split_words;
	int		i;

	i = 0;
	wordcount = count_words(s, c);
	split_words = malloc((wordcount + 1) * sizeof(char *));
	if (!split_words)
		return (NULL);
	split_words[wordcount] = NULL;
	while (i < wordcount && split_words)
	{
		while (*s == c)
			s++;
		lettercount = count_letters(s, c);
		split_words[i] = malloc((lettercount + 1) * sizeof(char));
		if (split_words[i])
			ft_strlcpy(split_words[i], s, lettercount + 1);
		else
			return (clean(split_words, i));
		s += lettercount;
		i++;
	}
	return (split_words);
}
