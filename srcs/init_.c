/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:34:57 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 10:22:48 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

float get_angle_for_play(t_player *player)
{
	if(player->c[0] == 'W')
		return(M_PI);
	else if(player->c[0] == 'S')
		return(1.5708);
	else if(player-> c[0] == 'E')
		return(0);
	else
		return 4.7277;
}
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