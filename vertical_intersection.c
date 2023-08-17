/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:50:39 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/17 09:07:50 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	vertical_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	//////////////////////////////////////
	//------------vertical ray-grid intersection code------------//
	//////////////////////////////////////
	t_player player = all->player;
	int wallHitX = 0;
	int wallHitY = 0;
	int distance = 0;

	float xIntercept;
	float yIntercept;
	float xStep;
	float yStep;
	ray->found_ver_wall_hit = 0;
	ray->verWallHitX = 0;
	ray->verWallHitY = 0;
	
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(rayAngle))
		xIntercept += TILE_SIZE;
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = player.y + (xIntercept - player.x) * tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	xStep = TILE_SIZE;             //xstep
	if (is_ray_facing_left(rayAngle))
	{
		xStep *= -1;
		xIntercept--;
	}
	yStep = TILE_SIZE * tan(rayAngle);//ystep
	if ((is_ray_facing_up(rayAngle) && yStep > 0) || (is_ray_facing_down(rayAngle) && yStep < 0))
		yStep *= -1;
	
	//incremet xstep and ystep until we find a wall
	while (xIntercept >= 0 && xIntercept <= WINDOW_WIDTH
		&& yIntercept >= 0 && yIntercept <= WINDOW_HEIGHT)
	{
		if (in_the_wall(xIntercept, yIntercept, all))
		{
			//we found a wall hit
			ray->found_ver_wall_hit = 1;
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
	ray->verWallHitX = wallHitX;
	ray->verWallHitY = wallHitY;
}