/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/18 16:12:54 by aessaoud         ###   ########.fr       */
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
	player->x = all->map.window_wid / 2;
	player->y = all->map.window_heig / 2;
	player->radius = 15;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = M_PI / 2;
	player->move_speed = 15.0;
	player->rotation_speed = 6 * (M_PI / 180); //convert to radian
}

void init_mlx(t_all *all)
{

}

int main(int c, char **args)
{
	struct s_map	map;
	int				fd;
	char			s[120];
	int				i;
	t_all			all;
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;

	if(c != 2 || checker_1(args) == -1)
		werror(1);
	map.tmp = 1;
	fd = open(args[1], O_RDONLY);
	if(fd < 0)
		werror(1);
	while(map.tmp != 0)
	{
		map.tmp = read(fd, s, 100);
		map.char_in_map += map.tmp;
	}
	close(fd);
	fd = open(args[1], O_RDONLY);
	// map.whole_map = malloc(map.char_in_map * sizeof(char) + 1); //no needed
	map.whole_map = ft_calloc(map.char_in_map + 1, 1);
	map.index = read(fd, map.whole_map, map.char_in_map);
	// map.whole_map[map.char_in_map] = '\0';                     //no needed
	
	// map.my_map = malloc(1 * sizeof(char*));                 //no needed
	// map.my_map[0] = NULL;                                  //no needed
	map.my_map = ft_calloc(1, 1);
	map.my_map = ft_split(map.whole_map, '\n');
	
	checker_2(&map);
	exctract(&map);
	
	//////////////////////////////////////////////////////////////////////
	//init mlx window
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, true);
	mlx_img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	all.map = map;
	all.rgb = map.rgb;
	//init player
	init_player(&player, &all);

	all.mlx = mlx;
	all.player = player;
	all.mlx_img = mlx_img;

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