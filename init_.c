/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:34:57 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/20 16:33:32 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	init_player(t_player *player, t_all *all)
{
	player->radius = 15;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = M_PI / 2;
	player->move_speed = 15.0;
	player->rotation_speed = 6 * (M_PI / 180); //convert to radian
}