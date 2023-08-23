/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_mbp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:49:05 by kslik             #+#    #+#             */
/*   Updated: 2023/08/23 11:49:36 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int	lines(struct s_map *map)
{
	return (map->lines);
}

int	extract_2(struct s_map *map, int start)
{
	int	i;
	int	j;

	map->pure_map = malloc(lines(map) * sizeof(char *) + 1);
	i = 0;
	while (map->my_map[start] != '\0')
	{
		j = 0;
		map->pure_map[i] = malloc(ft_strlen(map->my_map[start]) * sizeof(char)
				+ 1);
		while (map->my_map[start][j] != '\0')
		{
			map->pure_map[i][j] = map->my_map[start][j];
			j++;
		}
		map->pure_map[i][j] = '\0';
		start++;
		i++;
	}
	map->last_line = i - 1;
	map->pure_map[i] = NULL;
	return (1);
}

int	checker_map(struct s_map *map, int ply, int j)
{
	int	i;

	i = 0;
	while (map->pure_map[i] != NULL)
	{
		j = 0;
		while (map->pure_map[i][j + 1] != '\0')
		{
			if (map->pure_map[i][j] == 'N' || map->pure_map[i][j] == 'S')
				ply++;
			else if (map->pure_map[i][j] == 'E' || map->pure_map[i][j] == 'W')
				ply++;
			else if (map->pure_map[i][j] == '0' || map->pure_map[i][j] == '1'
					|| map->pure_map[i][j] == ' ')
				;
			else
				werror(1);
			j++;
		}
		i++;
	}
	if (ply != 1)
		werror(1);
	return (0);
}

int	check_around(struct s_map *map, int i, int j)
{
	if (i == 0 || i == map->last_line)
		werror(1);
	if (map->pure_map[i][j + 1] != '1' && map->pure_map[i][j + 1] != '0'
		&& !is_player(map->pure_map[i], j + 1))
		werror(1);
	if (map->pure_map[i][j - 1] != '1' && map->pure_map[i][j - 1] != '0'
		&& !is_player(map->pure_map[i], j - 1))
		werror(1);
	if (map->pure_map[i + 1][j] != '1' && map->pure_map[i + 1][j] != '0'
		&& !is_player(map->pure_map[i + 1], j))
		werror(1);
	if (map->pure_map[i - 1][j] != '1' && map->pure_map[i - 1][j] != '0'
		&& !is_player(map->pure_map[i - 1], j))
		werror(1);
	return (0);
}

int	check_valid(struct s_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->pure_map[i])
	{
		j = 0;
		while (map->pure_map[i][j] != '\0')
		{
			if (map->pure_map[i][j] == '0' || map->pure_map[i][j] == 'N')
				check_around(map, i, j);
			if (map->pure_map[i][j] == 'W' || map->pure_map[i][j] == 'S')
				check_around(map, i, j);
			if (map->pure_map[i][j] == 'E')
				check_around(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
