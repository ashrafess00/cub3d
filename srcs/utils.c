/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:57 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/22 16:37:42 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

// 18:53
// 22:31

float adjastAngle(float rayAngle)
{
	rayAngle = fmod(rayAngle, (2 * M_PI));
	if (rayAngle <= 0)
		rayAngle = (2 * M_PI) + rayAngle;
	return (rayAngle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	// return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool in_the_wall(float x, float y, t_all *all)
{
	int	m_x;
	int	m_y;

	if (x < 0 || x > all->map.window_wid || y < 0 || y > all->map.window_heig)
		return (1);
	m_x = floor(x / TILE_SIZE);
	m_y = floor(y / TILE_SIZE);
	printf("%d %d\n\n", m_x, m_y);
	if(all->map.pure_map[m_y][m_x] != '0' && is_player(all->map.pure_map[m_y], m_x) == 0)
		return (1);
	return (0);
}

t_rays fill_ray_direction(t_rays ray, float ray_angle)
{
	ray.is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	ray.is_ray_facing_up = !ray.is_ray_facing_down;
	ray.is_ray_facing_right = ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI);
	ray.is_ray_facing_left = !ray.is_ray_facing_right;
	return ray;
}