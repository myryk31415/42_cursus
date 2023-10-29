/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:25:18 by padam             #+#    #+#             */
/*   Updated: 2023/10/28 12:58:27 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_char_count(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (len);
}

int	fill_stat_buf(char **stat, char *buf, int len)
{
	free(*stat);
	*stat = NULL;
	if (len)
	{
		*stat = malloc(len + 1);
		if (!*stat)
			return (0);
		stat[0][len] = '\0';
		ft_memcpy(*stat, buf, len);
	}
	return (1);
}

// recursivly read from fd and store in buf
char	*recursive(char *line, int fd, int i, char **stat)
{
	char	buf_temp[BUFFER_SIZE];
	int		total_offset;
	int		read_return;
	int		cpy_count;

	total_offset = BUFFER_SIZE * i;
	if (*stat)
		total_offset += ft_strlen(*stat);
	read_return = read(fd, &buf_temp, BUFFER_SIZE);
	if (read_return == -1)
		return (NULL);
	cpy_count = read_return;
	if (read_return == BUFFER_SIZE && !ft_memchr(buf_temp, '\n', BUFFER_SIZE))
		line = recursive(line, fd, ++i, stat);
	else
	{
		if (ft_memchr(buf_temp, '\n', read_return))
			cpy_count = get_char_count(buf_temp, read_return);
		if (!fill_stat_buf(stat, buf_temp + cpy_count, read_return - cpy_count))
			return (NULL);
		if (total_offset + cpy_count == 0)
			return (NULL);
		line = malloc(total_offset + cpy_count + 2);
		line[total_offset + cpy_count] = '\0';
	}
	if (line)
		ft_memcpy(line + total_offset, buf_temp, cpy_count);
	return (line);
}

//read line from fd
char	*get_next_line(int fd)
{
	char				*line;
	static char			*stat[10240];
	char				temp[BUFFER_SIZE + 1];
	int					cpy_count;

	cpy_count = 0;
	line = NULL;
	*temp = '\0';
	if (BUFFER_SIZE < 1)
		return (NULL);
	if (stat[fd])
	{
		ft_strlcpy(temp, stat[fd], BUFFER_SIZE + 1);
		if (ft_memchr(temp, '\n', ft_strlen(temp)))
		{
			cpy_count = get_char_count(temp, ft_strlen(temp));
			line = malloc(cpy_count + 1);
			if (!line)
				return (NULL);
			line[cpy_count] = '\0';
			ft_memcpy(line, temp, cpy_count);
			if (!fill_stat_buf(&stat[fd], temp + cpy_count, ft_strlen(temp) - cpy_count))
				return (NULL);
			return (line);
		}
	}
	line = recursive(line, fd, 0, &stat[fd]);
	ft_memcpy(line, temp, ft_strlen(temp));
	return (line);
}
