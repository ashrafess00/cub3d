/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:50:39 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/22 09:54:39 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	vertical_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	//////////////////////////////////////
	//------------vertical ray-grid intersection code------------//
	//////////////////////////////////////
	t_player player = all->player;

	float	xIntercept;
	float	yIntercept;
	float	xStep;
	float	yStep;
	
	ray->found_ver_wall_hit = 0;
	ray->verWallHitX = 0;
	ray->verWallHitY = 0;
	*ray = fill_ray_direction(*ray, rayAngle);
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		xIntercept += TILE_SIZE;
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = player.y + (xIntercept - player.x) * tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	xStep = TILE_SIZE;             //xstep
	if (ray->is_ray_facing_left)
		xStep *= -1;
	yStep = TILE_SIZE * tan(rayAngle);//ystep
	if ((ray->is_ray_facing_up && yStep > 0) || (ray->is_ray_facing_down && yStep < 0))
		yStep *= -1;
	
	//incremet xstep and ystep until we find a wall
	while (xIntercept >= 0 && xIntercept <= all->map.window_wid
		&& yIntercept >= 0 && yIntercept <= all->map.window_heig)
	{
		float xToCheck = xIntercept + (ray->is_ray_facing_left ? -1 : 0);
		float yToCheck = yIntercept;
		if (in_the_wall(xToCheck, yToCheck, all))
		{
			//we found a wall hit
			ray->found_ver_wall_hit = 1;
			ray->verWallHitX = xIntercept;
			ray->verWallHitY = yIntercept;			
			break;
		}
		else
		{	
			xIntercept += xStep;
			yIntercept += yStep;
		}
	}
}