/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:25:18 by padam             #+#    #+#             */
/*   Updated: 2023/12/12 22:20:00 by padam            ###   ########.fr       */
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

char	*handle_stat(char *temp, char **stat)
{
	int		cpy_count;
	char	*line;

	line = NULL;
	cpy_count = get_char_count(temp, ft_strlen(temp));
	line = malloc(cpy_count + 1);
	if (!line)
	{
		free(*stat);
		*stat = NULL;
		return (NULL);
	}
	line[cpy_count] = '\0';
	ft_memcpy(line, temp, cpy_count);
	if (!fill_stat_buf(stat, temp + cpy_count, ft_strlen(temp) - cpy_count))
	{
		free (line);
		return (NULL);
	}
	return (line);
}

// recursivly read from fd and store in buf
char	*recursive(char *line, int fd, int i, char **stat)
{
	char	buf_tmp[BUFFER_SIZE];
	int		offset;
	int		r_out;
	int		cp;

	offset = BUFFER_SIZE * i;
	if (*stat)
		offset += ft_strlen(*stat);
	r_out = read(fd, &buf_tmp, BUFFER_SIZE);
	if (r_out == -1)
		return (NULL);
	cp = get_char_count(buf_tmp, r_out);
	if (cp == BUFFER_SIZE && !ft_memchr(buf_tmp, '\n', BUFFER_SIZE))
		line = recursive(line, fd, ++i, stat);
	else
	{
		if (!fill_stat_buf(stat, buf_tmp + cp, r_out - cp) || offset + cp == 0)
			return (NULL);
		line = malloc(offset + cp + 1);
		if (line)
			line[offset + cp] = '\0';
	}
	if (line)
		ft_memcpy(line + offset, buf_tmp, cp);
	return (line);
}

//read line from fd
char	*get_next_line(int fd)
{
	char				*line;
	static char			*stat[10240];
	char				temp[BUFFER_SIZE + 1];

	line = NULL;
	*temp = '\0';
	if (BUFFER_SIZE < 1)
		return (NULL);
	if (stat[fd])
	{
		ft_strlcpy(temp, stat[fd], BUFFER_SIZE + 1);
		if (ft_memchr(temp, '\n', ft_strlen(temp)))
			return (handle_stat(temp, &stat[fd]));
	}
	line = recursive(line, fd, 0, &stat[fd]);
	if (line)
		ft_memcpy(line, temp, ft_strlen(temp));
	else
	{
		free(stat[fd]);
		stat[fd] = NULL;
	}
	return (line);
}
