/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:53:18 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 13:48:42 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void draw_update_all(t_all *all)
{
	//rotation_angle (turn)
	all->player.rotation_angle = adjastAngle(all->player.rotation_angle);
	all->player.rotation_angle += all->player.turn_direction * all->player.rotation_speed;
	//walk
	int move_step = all->player.walk_direction * all->player.move_speed;
	
	int new_player_x = all->player.x + cos(all->player.rotation_angle) * move_step;
	int new_player_y = all->player.y + sin(all->player.rotation_angle) * move_step;
	
	// check the wall collision
	if (!in_the_wall(new_player_x, new_player_y, all))
	{
		all->player.x = new_player_x;
		all->player.y = new_player_y;
	}
	
	mlx_delete_image(all->mlx, all->mlx_img);
	all->mlx_img = mlx_new_image(all->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    //
	draw_map(all);
	//draw player
	draw_line(all->mlx_img, all->player.x,
                            all->player.y,
                            all->player.x + cos(all->player.rotation_angle) * 90,
                            all->player.y + sin(all->player.rotation_angle) * 90,
                            get_rgba(255, 0, 0, 255));
	draw_player(all->mlx_img, all->player.x, all->player.y);
	cast_rays(all);
	mlx_image_to_window(all->mlx, all->mlx_img, 0, 0);
}