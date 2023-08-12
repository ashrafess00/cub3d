/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/11 15:43:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

const float FOV_ANGLE = 60 * (M_PI / 180);
const int WALL_STRIP = 1;
const float NUM_RAYS = WINDOW_WIDTH / WALL_STRIP;

bool in_the_wall(int x, int y)
{
	int Map[MAP_ROWS][MAP_COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
									{1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
									{1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
									{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	int map_grip_index_x = floor(x / TILE_SIZE);
	int map_grip_index_y = floor(y / TILE_SIZE);

	return (Map[map_grip_index_y][map_grip_index_x] != 0);
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
		printf("%f\n", rayAngle);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		column++;
	}
	
}

int main(int c, char **args)
{
	// //3ndak tkhl3 rah ghir kantl9 yddi 😪

	t_all all;
	//init mlx window
	mlx_t *mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "بوسة فالفم خير من الدنيا وما فيها", true);
	mlx_image_t *mlx_img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	
	
	//init player
	t_player player;
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.radius = 15;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = M_PI / 2;
	player.move_speed = 10.0;
	player.rotation_speed = 10 * (M_PI / 180); //convert to radian

	all.mlx = mlx;
	all.player = player;
	all.mlx_img = mlx_img;
	//draw map
	draw_map(mlx_img);

	//draw player
	draw_player(mlx_img, player.x, player.y, player.radius, get_rgba(0, 255, 0, 255));
	draw_line(mlx_img, player.x, player.y, player.x + cos(player.rotation_angle) * 40, player.y + sin(player.rotation_angle) * 40, get_rgba(255, 0, 0, 255));
	cast_rays(&all);

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