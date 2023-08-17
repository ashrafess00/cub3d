/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/17 09:52:13 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

t_rays render_ray(t_all *all, float rayAngle, int column, int i, t_rays rays)
{
	float horzHitDistance;
	float verHitDistance;

	horizontal_intersection(all, rayAngle, &rays);
	vertical_intersection(all, rayAngle, &rays);
	if (rays.found_horz_wall_hit)
	{
		horzHitDistance = distance_between_points(all->player.x,
													all->player.y,
													rays.horzWallHitX,
													rays.horzWallHitY);
	}
	else
		horzHitDistance = 1111111111111;
	if (rays.found_ver_wall_hit)
	{
		verHitDistance = distance_between_points(all->player.x,
													all->player.y,
													rays.verWallHitX,
													rays.verWallHitY);
	}
	else
		verHitDistance = 1111111111111;

	if (horzHitDistance < verHitDistance)
	{
		rays.wall_hit_x = rays.horzWallHitX;
		rays.wall_hit_y = rays.horzWallHitY;
		rays.ray_distance = horzHitDistance;
	}
	else
	{
		rays.wall_hit_x = rays.verWallHitX;
		rays.wall_hit_y = rays.verWallHitY;
		rays.ray_distance = verHitDistance;
	}
	rays.ray_distance = rays.ray_distance * cos(rayAngle - all->player.rotation_angle);
	return (rays);
}

void	draw_casts(t_all *all, t_rays *rays)
{
	int	i;

	i = -1;
	while (++i < NUM_RAYS)
		draw_line(all->mlx_img, all->player.x, all->player.y, rays[i].wall_hit_x, rays[i].wall_hit_y, get_rgba(255, 0, 0, 255));
}
void cast_rays(t_all *all)
{
	int column = 0;
	t_rays rays[NUM_RAYS];
	// start first ray substracting half of the fov
	float rayAngle = all->player.rotation_angle - (FOV_ANGLE / 2);
	rayAngle = adjastAngle(rayAngle);
	//fill rays with info
	int i = -1;
	while (++i < NUM_RAYS)
	{
		rays[i] = render_ray(all, rayAngle, column, i, rays[i]);
		rayAngle += (FOV_ANGLE / NUM_RAYS);
		rayAngle = adjastAngle(rayAngle);
		column++;
	}

	//render walls
	i = -1;
	while (++i < NUM_RAYS)
		render_3d_project_walls(all, rays[i].ray_distance, i);
	draw_casts(all, rays);
}

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right