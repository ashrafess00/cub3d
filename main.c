/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/10 21:41:19 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

void update_player(t_all *all)
{
	all->player.rotation_angle += all->player.turn_direction * all->player.rotation_speed;
	// int move_step = all->player.walk_direction * move_speed;
	// all->player.x += move
	
	// mlx_delete_image(all->mlx, all->mlx_img);
	
	all->mlx_img = mlx_new_image(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	draw_map(all->mlx_img);
	//draw player
	draw_player(all->mlx_img, all->player.x, all->player.y, all->player.radius, get_rgba(0, 255, 0, 255));
	draw_line(all->mlx_img, all->player.x, all->player.y, all->player.x + cos(all->player.rotation_angle) * 30, all->player.y + sin(all->player.rotation_angle) * 30, get_rgba(255, 0, 0, 255));
	mlx_image_to_window(all->mlx, all->mlx_img, 0, 0);
}

void move_mama(mlx_key_data_t keydata, void *param)
{
	t_all *all = param;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		all->player.walk_direction += 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		all->player.walk_direction -= 1;
	else if (keydata.key == MLX_KEY_D)
		all->player.turn_direction += 1;
	else if (keydata.key == MLX_KEY_A)
		all->player.turn_direction -= 1;


	// else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	// 	all->player.walk_direction = 0;
	// else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	// 	all->player.walk_direction = 0;
	// else if (keydata.key == MLX_KEY_D)
	// 	all->player.turn_direction = 0;
	// else if (keydata.key == MLX_KEY_A)
	// 	all->player.turn_direction = 0;

	update_player(all);
	printf("walk directio: %d", all->player.walk_direction);
	
	
	if (keydata.key == MLX_KEY_D)
		printf("D\n");
	if (keydata.key == MLX_KEY_LEFT)
		printf("L\n");
	if (keydata.key == MLX_KEY_RIGHT)
		printf("R\n");
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
	player.move_speed = 2.0;
	player.rotation_speed = 3 * (M_PI / 180); //convert to radian

	all.mlx = mlx;
	all.player = player;
	all.mlx_img = mlx_img;
	//draw map
	draw_map(mlx_img);

	//draw player
	draw_player(mlx_img, player.x, player.y, player.radius, get_rgba(0, 255, 0, 255));
	draw_line(mlx_img, player.x, player.y, player.x + cos(player.rotation_angle) * 30, player.y + sin(player.rotation_angle) * 30, get_rgba(255, 0, 0, 255));


	mlx_key_hook(mlx, move_mama, &all);
	mlx_image_to_window(mlx, mlx_img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}