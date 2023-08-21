/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:48:02 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/21 23:08:03 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"



void horizontal_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	t_player player = all->player;

	float	xIntercept;
	float	yIntercept;
	float xStep;
	float yStep;
    
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
        // yIntercept--;
    }
	xStep = TILE_SIZE / tan(rayAngle);//xstep
	if ((ray->is_ray_facing_left && xStep > 0) || (ray->is_ray_facing_right && xStep < 0))
		xStep *= -1;
	
	//incremet xstep and ystep until we find a wall
	while (xIntercept >= 0 && xIntercept < all->map.window_wid
		&& yIntercept >= 0 && yIntercept < all->map.window_heig)
	{
		// if (in_the_wall(xIntercept, yIntercept, all))
		// {
		// 	//we found a wall hit
		// 	ray->found_horz_wall_hit = 1;
		// 	ray->horzWallHitX = xIntercept;
		// 	ray->horzWallHitY = yIntercept;
		// 	break;
		// }
		// else
		// {
		// 	xIntercept += xStep;
		// 	yIntercept += yStep;
		// }
		float xToCheck = xIntercept;
		float yToCheck = yIntercept + (ray->is_ray_facing_up ? -1 : 0);
		if (in_the_wall(xToCheck, yToCheck, all))
		{
			ray->horzWallHitX = xIntercept;
			ray->horzWallHitY = yIntercept;
			ray->found_horz_wall_hit = 1;
			break;
		}
		else
		{
			xIntercept += xStep;
			yIntercept += yStep;
		}
	}
}