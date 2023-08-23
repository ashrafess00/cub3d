/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:48:02 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 08:36:36 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"



void horizontal_intersection(t_all *all, float rayAngle, t_rays *ray)
{
	t_player player = all->player;

	float	xIntercept;
	float	y_intercept;
	float x_step;
	float y_step;
    float x_to_check;
	float	y_to_check;

	ray->found_horz_wall_hit = 0;
	ray->horzWallHitX = 0;
	ray->horzWallHitY = 0;
	*ray = fill_ray_direction(*ray, rayAngle);
	//find the y-coordinate of the closest horizontal grid intersections
	y_intercept = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		y_intercept += TILE_SIZE;
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = player.x + (y_intercept - player.y) / tan(rayAngle);

	//calculate the increment x_step and y_step
	y_step = TILE_SIZE;                //y_step
	if (ray->is_ray_facing_up)
		y_step *= -1;
	x_step = TILE_SIZE / tan(rayAngle);//x_step
	if ((ray->is_ray_facing_left && x_step > 0) || (ray->is_ray_facing_right && x_step < 0))
		x_step *= -1;
	//incremet x_step and y_step until we find a wall
	while (xIntercept >= 0 && xIntercept < all->map.window_wid
		&& y_intercept >= 0 && y_intercept < all->map.window_heig)
	{
		x_to_check = xIntercept;
		if (ray->is_ray_facing_up)
			y_to_check = y_intercept - 1;
		else
			y_to_check = y_intercept;
		if (in_the_wall(x_to_check, y_to_check, all))
		{
			ray->horzWallHitX = xIntercept;
			ray->horzWallHitY = y_intercept;
			ray->found_horz_wall_hit = 1;
			break;
		}
		else
		{
			xIntercept += x_step;
			y_intercept += y_step;
		}
	}
}