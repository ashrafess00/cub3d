/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:48:02 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 16:02:32 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int horizontal_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	t_player player = all->player;
	int wallHitX = 0;
	int wallHitY = 0;
	float distance = 0;

	float xIntercept;
	float yIntercept;
	float xStep;
	float yStep;
    int foundHorzWallHit = 0;
	
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(rayAngle))
		yIntercept += TILE_SIZE;
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = player.x + (yIntercept - player.y) / tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	yStep = TILE_SIZE;                //ystep
	if (is_ray_facing_up(rayAngle))
    {
		yStep *= -1;
        yIntercept--;
    }
	xStep = TILE_SIZE / tan(rayAngle);//xstep
	if ((is_ray_facing_left(rayAngle) && xStep > 0) || (is_ray_facing_right(rayAngle) && xStep < 0))
		xStep *= -1;
	
	
	//incremet xstep and ystep until we find a wall
	while (xIntercept >= 0 && xIntercept <= WINDOW_WIDTH
		&& yIntercept >= 0 && yIntercept <= WINDOW_HEIGHT)
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
	
	// return (foundHorzWallHit);
}