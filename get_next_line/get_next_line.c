/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:25:18 by padam             #+#    #+#             */
/*   Updated: 2023/10/19 19:33:54 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*recursive(char *line, int fd, int i)
{
	void	*buf;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	if (!ft_strchr(buf, '\n'))
	{
		line = recursive(line, fd, i++);
		ft_strlcat(line, buf);
	}
	else
	{
		line = malloc(i * BUFFER_SIZE + 1);
		i = ft_strchr(line, '\n') - line;
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*buf;
	char		*buf_temp;
	char		*line;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	recursive(line, fd, 0);
	return (line);
}
