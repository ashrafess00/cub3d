/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 12:35:24 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	get_horz_ver_distances(t_all *all, t_rays rays,
	float *horz_hit_distance, float *ver_hit_distance)
{
	if (rays.found_horz_wall_hit)
	{
		*horz_hit_distance = distance_between_points(all->player.x,
				all->player.y,
				rays.horzWallHitX,
				rays.horzWallHitY);
	}
	else
		*horz_hit_distance = INT_MAX;
	if (rays.found_ver_wall_hit)
	{
		*ver_hit_distance = distance_between_points(all->player.x,
				all->player.y,
				rays.verWallHitX,
				rays.verWallHitY);
	}
	else
		*ver_hit_distance = INT_MAX;
}

t_rays	render_ray(t_all *all, float ray_angle, int i, t_rays rays)
{
	float	horz_hit_distance;
	float	ver_hit_distance;

	horizontal_intersection(all, ray_angle, &rays);
	vertical_intersection(all, ray_angle, &rays);
	get_horz_ver_distances(all, rays, &horz_hit_distance, &ver_hit_distance);
	if (horz_hit_distance <= ver_hit_distance)
	{
		rays.main_wall_hit_x = rays.horzWallHitX;
		rays.main_wall_hit_y = rays.horzWallHitY;
		rays.ray_distance = horz_hit_distance;
		rays.found_horz_wall_hit = true;
		rays.found_ver_wall_hit = false;
	}
	else
	{
		rays.main_wall_hit_x = rays.verWallHitX;
		rays.main_wall_hit_y = rays.verWallHitY;
		rays.ray_distance = ver_hit_distance;
		rays.found_horz_wall_hit = false;
		rays.found_ver_wall_hit = true;
	}
	rays.ray_distance = rays.ray_distance * \
		cos(ray_angle - all->player.rotation_angle);
	return (rays);
}

void	get_rays(t_all *all, t_rays	*rays)
{
	int		i;
	float	ray_angle;

	ray_angle = all->player.rotation_angle - (FOV_ANGLE / 2);
	ray_angle = adjast_angle(ray_angle);
	i = -1;
	while (++i < NUM_RAYS)
	{
		rays[i] = render_ray(all, ray_angle, i, rays[i]);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		ray_angle = adjast_angle(ray_angle);
	}
}
