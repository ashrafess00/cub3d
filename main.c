/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/14 19:59:17 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

const float FOV_ANGLE = 60 * (M_PI / 180);
const int WALL_STRIP = 1;
const float NUM_RAYS = WINDOW_WIDTH / WALL_STRIP;

bool in_the_wall(int x, int y)
{
	int Map[MAP_ROWS][MAP_COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
									{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
									{1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1},
									{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	int map_grip_index_x = floor(x / TILE_SIZE);
	int map_grip_index_y = floor(y / TILE_SIZE);

	return (Map[map_grip_index_y][map_grip_index_x] != 1);
}



void update_player(t_all *all)
{
	//rotation_angle
	all->player.rotation_angle += all->player.turn_direction * all->player.rotation_speed;
	//walk
	int move_step = all->player.walk_direction * all->player.move_speed;
	
	int new_player_x = all->player.x + cos(all->player.rotation_angle) * move_step;
	int new_player_y = all->player.y + sin(all->player.rotation_angle) * move_step;
	
	//check the wall collision
	if (in_the_wall(new_player_x, new_player_y))
	{
		all->player.x = new_player_x;
		all->player.y = new_player_y;
	}
	
	all->mlx_img = mlx_new_image(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	draw_map(all->mlx_img);
	//draw player
	draw_player(all->mlx_img, all->player.x, all->player.y, all->player.radius, get_rgba(0, 255, 0, 255));
	draw_line(all->mlx_img, all->player.x, all->player.y, all->player.x + cos(all->player.rotation_angle) * 30, all->player.y + sin(all->player.rotation_angle) * 30, get_rgba(255, 0, 0, 255));
	cast_rays(all);
	mlx_image_to_window(all->mlx, all->mlx_img, 0, 0);
}

void render_ray(t_all *all, int rayAngle)
{
	draw_line(all->mlx_img,
				all->player.x,
				all->player.y,
				all->player.x + cos(rayAngle) * 30,
				all->player.y + sin(rayAngle) * 30,
				get_rgba(0, 0, 0, 255));
}

void cast_rays(t_all *all)
{
	t_player player = all->player;
	int column = 0;

	// start first ray substracting half of the fov
	float rayAngle = player.rotation_angle - (FOV_ANGLE / 2);

	//loop all comuns casting the rays
	int i = -1;
	while (++i < NUM_RAYS)
	{
		render_ray(all, rayAngle);
		// printf("%f\n", rayAngle);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		column++;
	}
	
}
void werror(int i)
{
	if(i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	init_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
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
	t_player player;
	struct s_map map;
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
	exctract(&map);
	// while(map.pure_map[++i])
	// 	printf("%s\n", map.pure_map[i]);
	exit(0);


	t_all all;
	//init mlx window
	mlx_t *mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "بوسة فالفم خير من الدنيا وما فيها", true);
	mlx_image_t *mlx_img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	
	
	//init player
	init_player(&player);

	all.mlx = mlx;
	all.player = player;
	all.mlx_img = mlx_img;
	//draw map
	draw_map(mlx_img);

	//draw player
	draw_player(mlx_img, player.x, player.y, player.radius, get_rgba(0, 255, 0, 255));
	draw_line(mlx_img, player.x, player.y, player.x + cos(player.rotation_angle) * 40, player.y + sin(player.rotation_angle) * 40, get_rgba(255, 0, 0, 255));
	cast_rays(&all);


	// int i = -1;
	// while(map.my_map[++i])
	// 	printf("%s\n", map.my_map[i]);

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