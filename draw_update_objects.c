/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:53:18 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/17 09:37:30 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

// void draw_update_all(t_all *all)
// {
// 	//rotation_angle (turn)
// 	all->player.rotation_angle = adjastAngle(all->player.rotation_angle);
// 	all->player.rotation_angle += all->player.turn_direction * all->player.rotation_speed;
// 	//walk
// 	int move_step = all->player.walk_direction * all->player.move_speed;
	
// 	int new_player_x = all->player.x + cos(all->player.rotation_angle) * move_step;
// 	int new_player_y = all->player.y + sin(all->player.rotation_angle) * move_step;
	
// 	// check the wall collision
// 	if (!in_the_wall(new_player_x, new_player_y, all))
// 	{
// 		all->player.x = new_player_x;
// 		all->player.y = new_player_y;
// 	}
	
// 	mlx_delete_image(all->mlx, all->mlx_img);
// 	all->mlx_img = mlx_new_image(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
//     //
// 	draw_map(all);
// 	//draw player
// 	draw_line(all->mlx_img, all->player.x,
//                             all->player.y,
//                             all->player.x + cos(all->player.rotation_angle) * 90,
//                             all->player.y + sin(all->player.rotation_angle) * 90,
//                             get_rgba(255, 0, 0, 255));
// 	draw_player(all->mlx_img, all->player.x, all->player.y);
// 	cast_rays(all);
// 	mlx_image_to_window(all->mlx, all->mlx_img, 0, 0);
// }

void draw_c_f(t_all *all)
{
	int i = 0;
	int j = 0;
	while(j < all->map.window_wid / 2)//sky
	{
		i =0;
		while(i < all->map.window_heig)
		{
			mlx_put_pixel(all->mlx_img, i, j, get_rgba(all->rgb.c[0],all->rgb.c[1],all->rgb.c[2],255));
			i++;
		}
		j++;
	}
	while(j < all->map.window_wid)//gorunf
	{
		i =0;
		while(i < all->map.window_heig)
		{
			mlx_put_pixel(all->mlx_img, i, j, get_rgba(all->rgb.f[0],all->rgb.f[1],all->rgb.f[2],255));
			i++;
		}
		j++;
	}
}


void draw_update_all(t_all *all)
{
	//rotation_angle
	all->player.rotation_angle = adjastAngle(all->player.rotation_angle);
	printf("angle : %f\n", all->player.rotation_angle);
	all->player.rotation_angle += all->player.turn_direction * all->player.rotation_speed;
	//walk
	int move_step = all->player.walk_direction * all->player.move_speed;
	
	int new_player_x = all->player.x + cos(all->player.rotation_angle) * move_step;
	int new_player_y = all->player.y + sin(all->player.rotation_angle) * move_step;
	
	if (new_player_x < 0 || new_player_x >= WINDOW_WIDTH || new_player_y < 0 || new_player_y >= WINDOW_HEIGHT)
		return;

	//check the wall collision
	if (!in_the_wall(new_player_x, new_player_y, all))
	{
		all->player.x = new_player_x;
		all->player.y = new_player_y;
	}
	
	mlx_delete_image(all->mlx, all->mlx_img);
	all->mlx_img = mlx_new_image(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//draw player
	draw_c_f(all);
	draw_map(all);
	cast_rays(all);
	draw_line(all->mlx_img, all->player.x, all->player.y, all->player.x + cos(all->player.rotation_angle) * 60, all->player.y + sin(all->player.rotation_angle) * 60, get_rgba(170, 200, 250, 255));
	draw_player(all->mlx_img, all->player.x, all->player.y);
	mlx_image_to_window(all->mlx, all->mlx_img, 0, 0);
}