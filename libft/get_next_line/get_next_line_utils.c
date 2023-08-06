/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:26:11 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_nl_found(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

char	*copy_rest(char *s)
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = (char *) ft_calloc(ft_strlen(s) + 1, 1);
	if (!new_str)
		return (0);
	while (s[++i])
		new_str[i] = s[i];
	return (new_str);
}

char	*expand(char *s1, char *s2)
{
	char	*new_str;
	int		new_str_size;
	int		i;
	int		new_str_i;

	new_str_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *) ft_calloc(new_str_size + 1, 1);
	if (!new_str)
		return (0);
	i = -1;
	new_str_i = 0;
	while (s1[++i])
		new_str[new_str_i++] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[new_str_i++] = s2[i];
	free (s1);
	free (s2);
	s2 = NULL;
	return (new_str);
}

void	split_line(char **line, char *rest)
{
	int		line_size;
	char	*new_str;
	int		i;
	int		j;

	line_size = 0;
	i = -1;
	while ((*line)[line_size] != '\n' && (*line)[line_size])
		line_size++;
	new_str = ft_calloc (line_size + 2, 1);
	if (!new_str)
		return ;
	while ((*line)[++i] != '\n' && (*line)[i])
		new_str[i] = (*line)[i];
	new_str[i] = (*line)[i];
	if (new_str[i] == '\n')
		i++;
	j = 0;
	while ((*line)[i])
		rest[j++] = (*line)[i++];
	rest[j] = '\0';
	free (*line);
	*line = new_str;
}
