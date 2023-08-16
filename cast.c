/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 13:52:42 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void render_ray(t_all *all, float rayAngle, int column, int i)
{
	int horzWallHitX;
	int horzWallHitY;
	int verWallHitX;
	int verWallHitY;
	int foundHorzWallHit = horizontal_intersection(all, rayAngle, &horzWallHitX, &horzWallHitY);
	int founVerWallHit = vertical_intersection(all, rayAngle, &verWallHitX, &verWallHitY);
	int horzHitDistance;
	int verHitDistance;
	int wallHitX;
	int wallHitY;
	float distance;
	if (foundHorzWallHit)
	{
		horzHitDistance = distanceBetweenPiints(all->player.x,
													all->player.y,
													horzWallHitX,
													horzWallHitY);
	}
	else
		horzHitDistance = 1111111111;
	if (founVerWallHit)
	{
		verHitDistance = distanceBetweenPiints(all->player.x,
													all->player.y,
													verWallHitX,
													verWallHitY);
	}
	else
		verHitDistance = 1111111111;

	if (horzHitDistance < verHitDistance)
	{
		wallHitX = horzWallHitX;
		wallHitY = horzWallHitY;
		distance = horzHitDistance;
	}
	else
	{
		wallHitX = verWallHitX;
		wallHitY = verWallHitY;
		distance = verHitDistance;
	}
	
	//to fix the distortion
	distance = distance * cos(rayAngle - all->player.rotation_angle);
	//render walls
	render_3d_project_walls(all->mlx_img, distance, i);
	if(foundHorzWallHit)
	{
		
		draw_line(all->mlx_img,
				all->player.x,
				all->player.y,
				wallHitX,
				wallHitY,
				get_rgba(255, 0, 0, 100));
	}
	else
	{		
		draw_line(all->mlx_img,
				all->player.x,
				all->player.y,
				wallHitX,
				wallHitY,0x00000FF);
		
	}
}



void cast_rays(t_all *all)
{
	int column = 0;

	// start first ray substracting half of the fov
	float rayAngle = all->player.rotation_angle - (FOV_ANGLE / 2);

	//loop all comuns casting the rays
	int i = -1;
	while (++i < NUM_RAYS)
	{
		render_ray(all, rayAngle, column, i);
		rayAngle += (FOV_ANGLE / NUM_RAYS);
		// printf("[[[[[[ray angle: %f]]]]]]\n", rayAngle);
		column++;
		// break;
		// printf("[ray count : %d]\n", i);
	}	
}

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right