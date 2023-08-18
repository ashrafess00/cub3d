/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:48:02 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/18 10:05:42 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"



void horizontal_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	t_player player = all->player;
	int wallHitX = 0;
	int wallHitY = 0;
	float distance = 0;

	float xIntercept;
	float yIntercept;
	float xStep;
	float yStep;
    // int foundHorzWallHit = 0;
	ray->found_horz_wall_hit = 0;
	ray->horzWallHitX = 0;
	ray->horzWallHitY = 0;
	*ray = fill_ray_direction(*ray, rayAngle);
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		yIntercept += TILE_SIZE;
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = player.x + (yIntercept - player.y) / tan(rayAngle);

	//calculate the increment xStep and yStep
	yStep = TILE_SIZE;                //ystep
	if (ray->is_ray_facing_up)
    {
		yStep *= -1;
        yIntercept--;
    }
	xStep = TILE_SIZE / tan(rayAngle);//xstep
	if ((ray->is_ray_facing_left && xStep > 0) || (ray->is_ray_facing_right && xStep < 0))
		xStep *= -1;
	
	//incremet xstep and ystep until we find a wall
	while (xIntercept >= 0 && xIntercept <= all->map.window_wid
		&& yIntercept >= 0 && yIntercept <= all->map.window_heig)
	{
		if (in_the_wall(xIntercept, yIntercept, all))
		{
			//we found a wall hit
			ray->found_horz_wall_hit = 1;
			wallHitX = xIntercept;
			wallHitY = yIntercept;
			break;
		}
		else
		{
			xIntercept += xStep;
			yIntercept += yStep;
		}
	}
	ray->horzWallHitX = wallHitX;
	ray->horzWallHitY = wallHitY;
	
}