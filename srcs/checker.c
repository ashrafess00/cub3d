/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:07:36 by kslik             #+#    #+#             */
/*   Updated: 2023/08/23 10:59:18 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	check_error(int i, int j, int f)
{
	if (f == 0)
	{
		if (i != 2 || j != 3)
			werror(1);
	}
}

void	while_map(struct s_map *map, struct s_checker *che, int i)
{
	while (map->my_map[i][che->jj] == ' ' && map->my_map[i][che->jj] != '\0')
		che->jj++;
}

int	check_color(struct s_map *map, int i, char c, struct s_checker *che)
{
	init_check(che, 1);
	while_map(map, che, i);
	if (map->my_map[i][che->jj] == c && map->my_map[i][che->jj + 1] == ' '
		&& map->my_map[i][che->jj + 1] != '\0')
		che->jj++;
	while (map->my_map[i][che->jj] == ' ' && map->my_map[i][che->jj] != '\0')
		che->jj++;
	while (map->my_map[i][che->jj] != '\0')
	{
		while_check(map, che, i);
		if (che->nmb > 255 || che->nmb < 0)
			werror(1);
		else
		{
			if (c == 'F')
				map->rgb.f[che->vld] = che->nmb;
			else if (c == 'C')
				map->rgb.c[che->vld] = che->nmb;
			che->vld++;
		}
		if (map->my_map[i][che->jj] == ',')
			che->jj++;
	}
	check_error(che->comma, che->vld, 0);
	return (1);
}

void	checker_3(struct s_map *map, struct s_checker *che)
{
	while (map->my_map[che->i][che->j] == ' '
		&& map->my_map[che->i][che->j] != '\0')
		che->j++;
	if (map->my_map[che->i][che->j] == 'N' && map->my_map[che->i][che->j
		+ 1] == 'O' && map->my_map[che->i][che->j + 2] == ' ')
		che->n += load_text_n(map, che->i, che->j + 2);
	else if (map->my_map[che->i][che->j] == 'S' && map->my_map[che->i][che->j
			+ 1] == 'O' && map->my_map[che->i][che->j + 2] == ' ')
		che->s += load_text_s(map, che->i, che->j + 2);
	else if (map->my_map[che->i][che->j] == 'W' && map->my_map[che->i][che->j
			+ 1] == 'E' && map->my_map[che->i][che->j + 2] == ' ')
		che->we += load_text_w(map, che->i, che->j + 2);
	else if (map->my_map[che->i][che->j] == 'E' && map->my_map[che->i][che->j
			+ 1] == 'A' && map->my_map[che->i][che->j + 2] == ' ')
		che->ea += load_text_e(map, che->i, che->j + 2);
	else if (map->my_map[che->i][che->j] == 'C' && map->my_map[che->i][che->j
			+ 1] == ' ')
		che->c += check_color(map, che->i, 'C', che);
	else if (map->my_map[che->i][che->j] == 'F' && map->my_map[che->i][che->j
			+ 1] == ' ')
		che->f += check_color(map, che->i, 'F', che);
}

int	checker_2(struct s_map *map)
{
	struct s_checker	che;

	init_check(&che, 0);
	while (map->my_map[che.k] != '\0')
		che.k++;
	che.ea = 0;
	che.i = 0;
	while (che.i < che.k)
	{
		che.j = 0;
		checker_3(map, &che);
		che.i++;
	}
	if (che.n != 1 || che.s != 1 || che.we != 1 || che.ea != 1 || che.c != 1
		|| che.f != 1)
		werror(1);
	return (1);
}
