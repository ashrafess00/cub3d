/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:48:02 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 13:54:53 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int horizontal_intersection(t_all *all, float rayAngle, int *horzWallHitX, int *horzWallHitY)
{
	t_player player = all->player;
	int wallHitX = 0;
	int wallHitY = 0;
	float distance = 0;

	float xIntercept;
	float yIntercept;
	float xStep;
	float yStep;

	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(rayAngle))
		yIntercept += TILE_SIZE;
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = player.x + (yIntercept - player.y) / tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	yStep = TILE_SIZE;                //ystep
	if (is_ray_facing_up(rayAngle))
		yStep *= -1;
	xStep = TILE_SIZE / tan(rayAngle);//xstep
	if (is_ray_facing_left(rayAngle) && xStep > 0)
		xStep *= -1;
	if (is_ray_facing_right(rayAngle) && xStep < 0)
		xStep *= -1;
	
	float nextHorzTouchX = xIntercept;
	float nextHorzTouchY = yIntercept;
	if (is_ray_facing_up(rayAngle))
		nextHorzTouchY--;
	
	int foundHorzWallHit = 0;
	//incremet xstep and ystep until we find a wall
	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH
		&& nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		if (in_the_wall(nextHorzTouchX, nextHorzTouchY, all))
		{
			//we found a wall hit
			foundHorzWallHit = 1;
			wallHitX = nextHorzTouchX;
			wallHitY = nextHorzTouchY;
			break;
		}
		else
		{
			nextHorzTouchX += xStep;
			nextHorzTouchY += yStep;
		}
	}
	*horzWallHitX = wallHitX;
	*horzWallHitY = wallHitY;
	
	return (foundHorzWallHit);
}