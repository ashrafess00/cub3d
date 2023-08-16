/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:50:39 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 13:50:52 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int vertical_intersection(t_all *all, float rayAngle, int *verWallHitX, int *verWallHitY)
{
	//////////////////////////////////////
	//------------vertical ray-grid intersection code------------//
	//////////////////////////////////////
	int foundVerWallHit = 0;
	t_player player = all->player;
	int wallHitX = 0;
	int wallHitY = 0;
	int distance = 0;

	float xIntercept;
	float yIntercept;
	float xStep;
	float yStep;

	
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(rayAngle))
		xIntercept += TILE_SIZE;
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = player.y + (xIntercept - player.x) * tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	xStep = TILE_SIZE;             //xstep
	if (is_ray_facing_left(rayAngle))
		xStep *= -1;
	yStep = TILE_SIZE * tan(rayAngle);//ystep
	if (is_ray_facing_up(rayAngle) && yStep > 0)
		yStep *= -1;
	if (is_ray_facing_down(rayAngle) && yStep < 0)
		yStep *= -1;
	
	float nextVerTouchX = xIntercept;
	float nextVerTouchY = yIntercept;
	if (is_ray_facing_left(rayAngle))
		nextVerTouchX--;
	
	//incremet xstep and ystep until we find a wall
	while (nextVerTouchX >= 0 && nextVerTouchX <= WINDOW_WIDTH
		&& nextVerTouchY >= 0 && nextVerTouchY <= WINDOW_HEIGHT)
	{
		if (in_the_wall(nextVerTouchX, nextVerTouchY, all))
		{
			//we found a wall hit
			foundVerWallHit = 1;
			wallHitX = nextVerTouchX;
			wallHitY = nextVerTouchY;			
			break;
		}
		else
		{
			nextVerTouchX += xStep;
			nextVerTouchY += yStep;
		}
	}
	*verWallHitX = wallHitX;
	*verWallHitY = wallHitY;
	
	return (foundVerWallHit);
}