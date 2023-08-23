/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:34:57 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 12:56:47 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	init_player(t_player *player, t_all *all)
{
	player->radius = 15;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = get_angle_for_play(player);
	player->move_speed = 15.0;
	player->rotation_speed = 6 * (M_PI / 180);
	player->move_side = 0;
	all->player = *player;
}

void	init_mlx(t_all *all)
{
	all->mlx = mlx_init(WIN_W, WIN_H, WINDOW_TITLE, true);
	all->mlx_img = mlx_new_image(all->mlx, WIN_W, WIN_H);
}

static void	count_line(struct s_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->whole_map[i] != '\0')
	{
		if (map->whole_map[i] == '\n')
			j++;
		i++;
	}
	map->lines = j;
}

static void	load_txt(struct s_map *map, struct s_all *all)
{
	all->txt.s_txt = mlx_load_png(map->txt.so_txt);
	all->txt.w_txt = mlx_load_png(map->txt.we_txt);
	all->txt.n_txt = mlx_load_png(map->txt.no_txt);
	all->txt.e_txt = mlx_load_png(map->txt.ea_txt);
	if (!(all->txt.s_txt && all->txt.w_txt && all->txt.n_txt && all->txt.e_txt))
	{
		if (all->txt.s_txt)
			mlx_delete_texture(all->txt.s_txt);
		if (all->txt.w_txt)
			mlx_delete_texture(all->txt.w_txt);
		if (all->txt.n_txt)
			mlx_delete_texture(all->txt.n_txt);
		if (all->txt.e_txt)
			mlx_delete_texture(all->txt.e_txt);
		werror(1);
	}
	free(map->txt.so_txt);
	free(map->txt.no_txt);
	free(map->txt.we_txt);
	free(map->txt.ea_txt);
}

void	init_map(t_all *all, t_player *player, char *file)
{
	struct s_map	map;
	int				fd;
	char			s[120];

	map.tmp = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		werror(1);
	while (map.tmp != 0)
	{
		map.tmp = read(fd, s, 100);
		map.char_in_map += map.tmp;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	map.whole_map = ft_calloc(map.char_in_map + 1, 1);
	map.index = read(fd, map.whole_map, map.char_in_map);
	count_line(&map);
	map.my_map = ft_split(map.whole_map, '\n');
	checker_2(&map);
	exctract(&map, player, 0, 0);
	load_txt(&map, all);
	all->map = map;
	all->rgb = map.rgb;
}
