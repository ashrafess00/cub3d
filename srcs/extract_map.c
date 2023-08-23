/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:28:15 by kslik             #+#    #+#             */
/*   Updated: 2023/08/23 11:53:18 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int	is_player(char *s, int i)
{
	if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
		return (1);
	return (0);
}

int	get_ply_cor(struct s_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->pure_map[i])
	{
		j = 0;
		while (map->pure_map[i][j])
		{
			if (is_player(map->pure_map[i], j))
			{
				player->x = j * TILE_SIZE;
				player->y = i * TILE_SIZE;
				player->c = malloc(3 * sizeof(char));
				player->c[0] = map->pure_map[i][j];
				player->c[1] = '\0';
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_wi_he(struct s_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->window_wid = 0;
	while (map->pure_map[i])
	{
		j = 0;
		while (map->pure_map[i][j] != '\0')
			j++;
		if (j * TILE_SIZE > map->window_wid)
			map->window_wid = j * TILE_SIZE;
		i++;
	}
	map->window_heig = i * TILE_SIZE;
	return (0);
}

void	call_checkers(struct s_map *map, int start, t_player *player)
{
	extract_2(map, start);
	checker_map(map, 0, 0);
	check_valid(map);
	check_mty_line(map, start);
	get_wi_he(map);
	get_ply_cor(map, player);
}

int	exctract(struct s_map *map, t_player *player, int ma, int j)
{
	int	i;
	int	start;

	i = 5;
	while (map->my_map[i] != '\0')
	{
		while (map->my_map[i][j] == ' ' && map->my_map[i][j] != '\0')
			j++;
		if (map->my_map[i][j] == '1' || map->my_map[i][j] == '0')
			break ;
		i++;
	}
	while (map->my_map[i][j] == '1' && map->my_map[i][j] != '\0')
	{
		j++;
		ma++;
	}
	if (ma >= 4)
		start = i;
	else
		werror(1);
	call_checkers(map, start, player);
	return (0);
}
