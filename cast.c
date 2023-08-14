/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/14 12:22:34 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

// const float FOV_ANGLE = 60 * (M_PI / 180);
// const int WALL_STRIP = 3;
// const float NUM_RAYS = WINDOW_WIDTH / WALL_STRIP;


int is_ray_facing_down(float rayAngle)
{
	if (rayAngle > 0 && rayAngle < M_PI)
		return (1);
	return (0);	
}
int is_ray_facing_up(float rayAngle)
{
	return (!is_ray_facing_down(rayAngle));
}
int is_ray_facing_right(float rayAngle)
{
    if (rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI)
        return (1);
    return 0;
}
int is_ray_facing_left(float rayAngle)
{
    return (!is_ray_facing_right(rayAngle));
}

float adjastAngle(float rayAngle)
{
	rayAngle = fmod(rayAngle, (int)(2 * M_PI));
	if (rayAngle < 0)
		rayAngle = (2 * M_PI) + rayAngle;
	return (rayAngle);
}

float distanceBetweenPiints(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void print_face(float rayAngle)
{
	if (is_ray_facing_down(rayAngle))
		printf("is facing down\n");
	if (is_ray_facing_up(rayAngle))
		printf("is facing up\n");
	if (is_ray_facing_left(rayAngle))
		printf("is facing left\n");
	if (is_ray_facing_right(rayAngle))
		printf("is facing right\n");
	printf("-------\n");
}

void render_ray(t_all *all, float rayAngle, int column)
{
	// int wallHitx = 0;
	// int wallHity = 0;
	// int distance = 0;
	// int wasHitVertical = 0;
	// rayAngle = adjastAngle(rayAngle);
	
	// ////////////////////////////////////////////
	// //////// horizontal ray-grid intersection//
	// ////////////////////////////////////////////
	// int xIntercept, yIntercept;
	// int xStep, yStep;
	
	// print_face(rayAngle);
	// //find y-cordinate at the closet horizontal grid
	// yIntercept = floor((all->player.y / TILE_SIZE))  * TILE_SIZE;
    // if(is_ray_facing_down(rayAngle))
	// 	yIntercept += TILE_SIZE;
	// //find x -cordinate at the closet horizontal grid
	// xIntercept = all->player.x + (yIntercept - all->player.y) / tan(rayAngle);
	
	// //calculate the increment xstep and ystep
	// yStep = TILE_SIZE;
	// if (is_ray_facing_up(rayAngle))
	// 	yStep *= -1;
	// xStep = TILE_SIZE / tan(rayAngle);
    // if (is_ray_facing_left(rayAngle) && xStep > 0)
	// 	xStep *= -1;
	// if (is_ray_facing_right(rayAngle) && xStep < 0)
	// 	xStep *= -1;
	
	// int nextHorzTouchX = xIntercept;
	// int nextHorzTouchY = yIntercept;
	// if(is_ray_facing_up(rayAngle))
	// 	nextHorzTouchY--;

	// //increment xstep and ystep until we find a wall
	// int foundHorzWallHit = 0;
	// int HorzwallHitX = 0;
	// int HorzwallHitY = 0;
	// while (nextHorzTouchX >= 0 &&
	// 		nextHorzTouchX <= WINDOW_WIDTH &&
	// 		nextHorzTouchY >= 0 &&
	// 		nextHorzTouchY <= WINDOW_HEIGHT) {
	// 	if (in_the_wall(nextHorzTouchX, nextHorzTouchY)) {
	// 		foundHorzWallHit = 1;
	// 		HorzwallHitX = nextHorzTouchX;
	// 		HorzwallHitY = nextHorzTouchY;

	// 		// draw_line(all->mlx_img,
	// 		// 	all->player.x,
	// 		// 	all->player.y,
	// 		// 	HorzwallHitX,
	// 		// 	HorzwallHitY,
	// 		// 	get_rgba(0, 0, 0, 255));
			
	// 		break;
	// 	}
	// 	else {
	// 		nextHorzTouchX += xStep;
	// 		nextHorzTouchY += yStep;
	// 	}
	// }

	

	// ////////////////////////////////////////////
	// //////// vertical ray-grid intersection//
	// ////////////////////////////////////////////
	// int foundVerWallHit = 0;
	// int VerwallHitX = 0;
	// int VerwallHitY = 0;
	
	// //find x-cordinate at the closet vertical grid
	// xIntercept = floor((all->player.x / TILE_SIZE))  * TILE_SIZE;
    // if(is_ray_facing_right(rayAngle))
	// 	yIntercept += TILE_SIZE;
	// //find y -cordinate at the closet vertical grid
	// yIntercept = all->player.y + (xIntercept - all->player.x) * tan(rayAngle);
	
	// //calculate the increment xstep and ystep
	// xStep = TILE_SIZE;
	// if (is_ray_facing_left(rayAngle))
	// 	xStep *= -1;
	// yStep = TILE_SIZE / tan(rayAngle);
    // if (is_ray_facing_up(rayAngle) && yStep > 0)
	// 	yStep *= -1;
	// if (is_ray_facing_down(rayAngle) && yStep < 0)
	// 	yStep *= -1;
	
	// int nextVerTouchX = xIntercept;
	// int nextVerTouchY = yIntercept;
	// if(is_ray_facing_left(rayAngle))
	// 	nextVerTouchX--;

	// //increment xstep and ystep until we find a wall
	
	// while (nextVerTouchX >= 0 &&
	// 		nextVerTouchX <= WINDOW_WIDTH &&
	// 		nextVerTouchY >= 0 &&
	// 		nextVerTouchY <= WINDOW_HEIGHT) {
	// 	if (in_the_wall(nextVerTouchX, nextVerTouchY)) {
	// 		foundVerWallHit = 1;
	// 		VerwallHitX = nextVerTouchX;
	// 		VerwallHitY = nextVerTouchY;

	// 		// draw_line(all->mlx_img,
	// 		// 	all->player.x,
	// 		// 	all->player.y,
	// 		// 	VerwallHitX,
	// 		// 	VerwallHitY,
	// 		// 	get_rgba(0, 0, 0, 255));
			
	// 		break;
	// 	}
	// 	else {
	// 		nextVerTouchX += xStep;
	// 		nextVerTouchY += yStep;
	// 	}
	// }


	// //calculate both horz and ver distances and chose the smallest value
	// float horzHitDistance = (foundHorzWallHit) ? distanceBetweenPiints(
	// 	all->player.x,
	// 	all->player.y,
	// 	HorzwallHitX,
	// 	HorzwallHitY
	// ) : 11111111111;

	// float VerHitDistance = (foundHorzWallHit) ? distanceBetweenPiints(
	// 	all->player.x,
	// 	all->player.y,
	// 	VerwallHitX,
	// 	VerwallHitY
	// ) : 11111111111;
	
	// //only store the smallest distances
	// wallHitx = (horzHitDistance < VerHitDistance) ? HorzwallHitX : VerwallHitX;
	// wallHity = (horzHitDistance < VerHitDistance) ? HorzwallHitY : VerwallHitY;
	// distance = (horzHitDistance < VerHitDistance) ? horzHitDistance : VerHitDistance;
	// wasHitVertical = (VerHitDistance < horzHitDistance);
	
	
	

	//draw line
	// draw_line(all->mlx_img,
	// 			all->player.x,
	// 			all->player.y,
	// 			wallHitx,
	// 			wallHity,
	// 			get_rgba(0, 0, 0, 255));
	draw_line(all->mlx_img,
			all->player.x,
			all->player.y,
			all->player.x + cos(rayAngle) * 50,
			all->player.y + sin(rayAngle) * 50,
			get_rgba(0, 0, 0, 255));
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
		render_ray(all, rayAngle, column);
		rayAngle += (FOV_ANGLE / NUM_RAYS);
		printf("[[[[[[ray angle: %f]]]]]]\n", rayAngle);
		column++;
		// break;
	}	
}