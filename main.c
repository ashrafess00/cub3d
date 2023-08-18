/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/18 13:44:43 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void werror(int i)
{
	if(i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	init_player(t_player *player, t_all *all)
{
	player->radius = 15;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = M_PI / 2;
	player->move_speed = 15.0;
	player->rotation_speed = 15 * (M_PI / 180); //convert to radian
}

int main(int c, char **args)
{

	if(c != 2)
		werror(1);
	struct s_map map;
	t_player player;
	if(checker_1(args) == -1)
		werror(1);
	map.tmp = 1;
	int fd = open(args[1], O_RDONLY);
	if(fd < 0)
		werror(1);
	char s[120];
	while(map.tmp != 0)
	{
		map.tmp = read(fd, s, 100);
		map.char_in_map += map.tmp;
	}
	close(fd);
	fd = open(args[1], O_RDONLY);
	map.whole_map = malloc(map.char_in_map * sizeof(char) + 1);
	map.index = read(fd, map.whole_map, map.char_in_map);
	map.whole_map[map.char_in_map] = '\0';
	map.my_map = malloc(1 * sizeof(char*));
	map.my_map[0] = NULL;
	map.my_map = ft_split(map.whole_map, '\n');
	int i = -1;
	checker_2(&map);
	exctract(&map, &player);
	t_all all;
	//init mlx window
	mlx_t *mlx = mlx_init(map.window_wid,map.window_heig, WINDOW_TITLE, true);
	mlx_image_t *mlx_img = mlx_new_image(mlx, map.window_heig,map.window_wid);
	all.map = map;
	all.rgb = map.rgb;
	
	//init player
	init_player(&player, &all);

	all.mlx = mlx;
	all.player = player;
	all.mlx_img = mlx_img;
	//draw map
	// draw_map(mlx_img);

	//draw all
	draw_update_all(&all);
	mlx_key_hook(mlx, move_mama, &all);
	mlx_image_to_window(mlx, mlx_img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
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