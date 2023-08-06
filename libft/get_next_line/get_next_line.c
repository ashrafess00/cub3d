/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:49:54 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_eof(char **line, int read_size)
{
	if (!*(*line) && read_size <= 0)
	{
		free (*line);
		*line = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE];
	char		*line;
	int			read_size;
	char		*lghrraf;

	if (fd < 0 || fd >= OPEN_MAX)
		return (0);
	read_size = 1;
	line = ft_calloc(1, 1);
	if (!line)
		return (0);
	if (*rest)
		line = expand(copy_rest(rest), line);
	while (read_size > 0 && !is_nl_found(line))
	{
		lghrraf = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		if (!lghrraf)
			return (0);
		read_size = read(fd, lghrraf, BUFFER_SIZE);
		line = expand(line, lghrraf);
	}
	split_line(&line, rest);
	check_eof(&line, read_size);
	return (line);
}
