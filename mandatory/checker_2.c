/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:38 by kslik             #+#    #+#             */
/*   Updated: 2023/08/23 12:58:14 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int	error_ber(char *av)
{
	int	i;
	int	fl;

	i = 0;
	fl = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '.')
			fl++;
		i++;
	}
	if (fl > 1)
		return (0);
	i = 0;
	while (av[i + 4] != '\0')
		i++;
	if (av[i] != '.' || av[i + 1] != 'c' || av[i + 2] != 'u' || av[i + 3] != 'b'
		|| av[i + 4] != '\0')
		return (0);
	return (1);
}

int	checker_1(char **args)
{
	if (args[1] == '\0')
		return (-1);
	if (error_ber(args[1]) == 0)
		return (-1);
	return (1);
}

void	init_check(struct s_checker *check, int i)
{
	if (i == 0)
	{
		check->i = 0;
		check->k = 0;
		check->n = 0;
		check->s = 0;
		check->we = 0;
		check->ea = 0;
		check->j = 0;
		check->c = 0;
		check->f = 0;
	}
	else
	{
		check->nmb = 0;
		check->tmp = 0;
		check->comma = 0;
		check->vld = 0;
		check->jj = 0;
	}
}

void	while_check(struct s_map *map, struct s_checker *che, int i)
{
	che->tmp = che->jj;
	while (map->my_map[i][che->jj] != ',' && map->my_map[i][che->jj] != '\0')
	{
		if (map->my_map[i][che->jj] > 31 && map->my_map[i][che->jj] < 126
			&& map->my_map[i][che->jj] != '\0')
		{
			if (map->my_map[i][che->jj] < 48 || map->my_map[i][che->jj] > 57)
				werror(1);
		}
		che->jj++;
	}
	if (map->my_map[i][che->jj] == ',')
		che->comma++;
	else if (map->my_map[i][che->jj] != '\0')
		werror(1);
	if (che->tmp - che->jj == 0)
		werror(1);
	che->q = ft_substr(map->my_map[i], che->tmp, che->jj - che->tmp);
	che->nmb = ft_atoi(che->q);
	free(che->q);
}

bool	in_the_wall(float x, float y, t_all *all)
{
	int	m_x;
	int	m_y;

	if (x < 0 || x > all->map.win_w || y < 0 || y > all->map.win_h)
		return (1);
	m_x = floor(x / TILE_SIZE);
	m_y = floor(y / TILE_SIZE);
	if (all->map.pure_map[m_y][m_x] != '0' && is_player(all->map.pure_map[m_y],
			m_x) == 0)
		return (1);
	return (0);
}
