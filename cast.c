/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/13 13:21:30 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

const float FOV_ANGLE = 60 * (M_PI / 180);
const int WALL_STRIP = 3;
const float NUM_RAYS = WINDOW_WIDTH / WALL_STRIP;


int is_ray_facing_down(float rayAngle)
{
	if (rayAngle > 0 && rayAngle < M_PI)
		return (1);
	return (0);	
}
int is_ray_facing_up(float rayAngle)
{
	return (!is_ray_facing_down(rayAngle));
}
int is_ray_facing_right(float rayAngle)
// {	
// }

void render_ray(t_all *all, float rayAngle, int column)
{
	int wallHitx = 0;
	int wallHity = 0;
	int distance = 0;
	
	//////// horizontal ray-grid intersection
	int xIntercept, yIntercept;
	int xStep, yStep;
	
	//find y-cordinate at the closet horizontal grid
	yIntercept = floor((all->player.y / TILE_SIZE))  * TILE_SIZE;

	//find x -cordinate at the closet horizontal grid
	xIntercept = all->player.x + (yIntercept - all->player.y) / tan(rayAngle);
	
	// rayAngle = normalize_angle(rayAngle);
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
		render_ray(all, rayAngle, column);
		// printf("%f\n", rayAngle);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		column++;
	}	
}