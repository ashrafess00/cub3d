/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:57 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/17 10:25:04 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

// 18:53
// 22:31
float distanceBetweenPoint(int x1, int y1, int x2, int y2)
{
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

float adjastAngle(float rayAngle)
{
	rayAngle = fmod(rayAngle, (2 * M_PI));
	if (rayAngle <= 0)
		rayAngle = (2 * M_PI) + rayAngle;
	return (rayAngle);
}

float distance_between_points(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}


bool in_the_wall(int x, int y, t_all *all)
{

	int map_grip_index_x = floor(x / TILE_SIZE);
	int map_grip_index_y = floor(y / TILE_SIZE);
	return (all->map.pure_map[map_grip_index_y][map_grip_index_x] != '0');
}

t_rays fill_ray_direction(t_rays ray, float ray_angle)
{
	ray.is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	ray.is_ray_facing_up = !ray.is_ray_facing_down;
	ray.is_ray_facing_right = ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI);
	ray.is_ray_facing_left = !ray.is_ray_facing_right;
	return ray;
}