/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:57 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 16:03:30 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header_bonus.h"

float	get_angle_for_play(t_player *player)
{
	if (player->c[0] == 'W')
		return (M_PI);
	else if (player->c[0] == 'S')
		return (1.5708);
	else if (player->c[0] == 'E')
		return (0);
	else
		return (4.7277);
}

float	adjast_angle(float ray_angle)
{
	ray_angle = fmod(ray_angle, (2 * M_PI));
	if (ray_angle <= 0)
		ray_angle = (2 * M_PI) + ray_angle;
	return (ray_angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

t_rays	fill_ray_direction(t_rays ray, float ray_angle)
{
	ray.is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	ray.is_ray_facing_up = !ray.is_ray_facing_down;
	ray.is_ray_facing_right = ray_angle < (0.5 * M_PI) || ray_angle > (1.5
			* M_PI);
	ray.is_ray_facing_left = !ray.is_ray_facing_right;
	return (ray);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
