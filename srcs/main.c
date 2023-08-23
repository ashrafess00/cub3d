/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 08:59:08 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	werror(int i)
{
	if (i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	load_txt(struct s_map *map, struct s_all *all)
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
}
void count_line(struct s_map *map )
{
	int i = 0;
	int j = 0;
	while(map->whole_map[i] != '\0')
	{
		if(map->whole_map[i] == '\n')
			j++;
		i++;
	}
	map->lines = j;
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
	exctract(&map, player);
	load_txt(&map, all);
	all->map = map;
	all->rgb = map.rgb;
}

int	main(int c, char **args)
{
	t_all			all;
	t_player		player;

	if (c != 2 || checker_1(args) == -1)
		werror(1);
	init_map(&all, &player, args[1]);
	init_mlx(&all);
	init_player(&player, &all);
	
	//draw all
	mlx_image_to_window(all.mlx, all.mlx_img, 0, 0);
	draw_update_all(&all);
	mlx_key_hook(all.mlx, move_mama, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}

//ray casting steps
//1- substract 30 degrees from player rotaion angle fov/2
//2- start at column 0
//3- while(column < 320)
	// *cast a ray
	// tracet he rau until it intersects with a wall(map[i][j] == 1)
	//record the intersection (x, y) and the distance (ray lenght)
		//rayAngle += 60 / 320;  (60 will be converted to rad)
////render wall line 46