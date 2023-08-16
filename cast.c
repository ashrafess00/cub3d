/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 12:03:15 by aessaoud         ###   ########.fr       */
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
	rayAngle = fmod(rayAngle, (2 * M_PI));
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
// 18:53
// 22:31
float distanceBetweenPoint(int x1, int y1, int x2, int y2)
{
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}


int horizontal_intersection(t_all *all, float rayAngle, int *horzWallHitX, int *horzWallHitY)
{
	//////////////////////////////////////
	//------------horizontal ray-grid intersection code------------//
	//////////////////////////////////////
	t_player player = all->player;
	int wallHitX = 0;
	int wallHitY = 0;
	float distance = 0;

	float xIntercept;
	float yIntercept;
	float xStep;
	float yStep;

	int isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
	int isRayFacingUp = !isRayFacingDown;
	int isRayFacingRight = rayAngle < (M_PI / 2) || rayAngle > 1.5 * M_PI;
	int isRayFacingLeft = !isRayFacingRight;

	
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
	if (isRayFacingDown)
		yIntercept += TILE_SIZE;
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = player.x + (yIntercept - player.y) / tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	yStep = TILE_SIZE;                //ystep
	if (isRayFacingUp)
		yStep *= -1;
	xStep = TILE_SIZE / tan(rayAngle);//xstep
	if (isRayFacingLeft && xStep > 0)
		xStep *= -1;
	if (isRayFacingRight && xStep < 0)
		xStep *= -1;
	
	float nextHorzTouchX = xIntercept;
	float nextHorzTouchY = yIntercept;
	if (isRayFacingUp)
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

	int isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
	int isRayFacingUp = !isRayFacingDown;
	int isRayFacingRight = rayAngle < (M_PI / 2) || rayAngle > 1.5 * M_PI;
	int isRayFacingLeft = !isRayFacingRight;

	
	//find the x-coordinate of the closest horizontal grid intersections
	xIntercept = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	if (isRayFacingRight)
		xIntercept += TILE_SIZE;
	//find the y-coordinate of the closest horizontal grid intersections
	yIntercept = player.y + (xIntercept - player.x) * tan(rayAngle);//warning

	//calculate the increment xStep and yStep
	xStep = TILE_SIZE;             //xstep
	if (isRayFacingLeft)
		xStep *= -1;
	yStep = TILE_SIZE * tan(rayAngle);//ystep
	if (isRayFacingUp && yStep > 0)
		yStep *= -1;
	if (isRayFacingDown && yStep < 0)
		yStep *= -1;
	
	float nextVerTouchX = xIntercept;
	float nextVerTouchY = yIntercept;
	if (isRayFacingLeft)
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