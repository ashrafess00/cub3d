/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/09 13:19:20 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"



int main(int c, char **args)
{
	// //3ndak tkhl3 rah ghir kantl9 yddi 😪

	//init mlx window
	mlx_t *mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "bosa fl fmm khayron mina donya wama fiha", true);
	mlx_image_t *mlx_img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	
	//init player
	t_player player;
	player.x = 150;
	player.y = 150;
	player.radius = 10;
	player.turn_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = M_PI / 2;
	player.move_speed = 3.0;
	player.rotation_speed = 3 * (M_PI / 180);

	//draw map
	draw_map(mlx_img);

	//draw player
	draw_player(mlx_img, player.x, player.y, player.radius, get_rgba(0, 255, 0, 255));
	
	mlx_image_to_window(mlx, mlx_img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}