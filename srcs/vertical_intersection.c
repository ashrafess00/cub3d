/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:50:39 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/22 21:10:12 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	vertical_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	//////////////////////////////////////
	//------------vertical ray-grid intersection code------------//
	//////////////////////////////////////
	t_player player = all->player;

	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	float	y_to_check;
	float	x_to_check;

	ray->found_ver_wall_hit = 0;
	ray->verWallHitX = 0;
	ray->verWallHitY = 0;
	*ray = fill_ray_direction(*ray, rayAngle);
	//find the x-coordinate of the closest horizontal grid intersections
	x_intercept = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		x_intercept += TILE_SIZE;
	//find the y-coordinate of the closest horizontal grid intersections
	y_intercept = player.y + (x_intercept - player.x) * tan(rayAngle);//warning

	//calculate the increment x_step and y_step
	x_step = TILE_SIZE;             //x_step
	if (ray->is_ray_facing_left)
		x_step *= -1;
	y_step = TILE_SIZE * tan(rayAngle);//y_step
	if ((ray->is_ray_facing_up && y_step > 0) || (ray->is_ray_facing_down && y_step < 0))
		y_step *= -1;
	
	//incremet x_step and y_step until we find a wall
	while (x_intercept >= 0 && x_intercept <= all->map.win_w
		&& y_intercept >= 0 && y_intercept <= all->map.win_h)
	{
		// float xToCheck = x_intercept + (ray->is_ray_facing_left ? -1 : 0);
		y_to_check = y_intercept;
		if (ray->is_ray_facing_left)
			x_to_check = x_intercept - 1;
		else
			x_to_check = x_intercept;
		if (in_the_wall(x_to_check, y_to_check, all))
		{
			//we found a wall hit
			ray->found_ver_wall_hit = 1;
			ray->verWallHitX = x_intercept;
			ray->verWallHitY = y_intercept;			
			break;
		}
		else
		{	
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
}