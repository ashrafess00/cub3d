/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/21 08:56:07 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

t_rays render_ray(t_all *all, float rayAngle, int column, int i, t_rays rays)
{
	float horzHitDistance;
	float verHitDistance;
	horizontal_intersection(all, rayAngle, &rays);
	vertical_intersection(all, rayAngle, &rays);   //segv hna

	if (rays.found_horz_wall_hit)
	{
		horzHitDistance = distance_between_points(all->player.x,
													all->player.y,
													rays.horzWallHitX,
													rays.horzWallHitY);
	}
	else
		horzHitDistance = 1111111;
	if (rays.found_ver_wall_hit)
	{
		verHitDistance = distance_between_points(all->player.x,
													all->player.y,
													rays.verWallHitX,
													rays.verWallHitY);
	}
	else
		verHitDistance = 1111111;

	if (horzHitDistance < verHitDistance)
	{
		rays.wall_hit_x = rays.horzWallHitX;
		rays.wall_hit_y = rays.horzWallHitY;
		rays.ray_distance = horzHitDistance;
		rays.found_horz_wall_hit = 1;
		rays.found_ver_wall_hit = 0;
	}
	else
	{
		rays.wall_hit_x = rays.verWallHitX;
		rays.wall_hit_y = rays.verWallHitY;
		rays.ray_distance = verHitDistance;
		rays.found_ver_wall_hit = 1;
		rays.found_horz_wall_hit = 0;
	}
	rays.ray_distance = rays.ray_distance * cos(rayAngle - all->player.rotation_angle);
	return (rays);
}

void	draw_casts(t_all *all, t_rays *rays)
{
	int	i;

	i = -1;
	while (++i < NUM_RAYS)
		draw_line(all, all->player.x, all->player.y, rays[i].wall_hit_x, rays[i].wall_hit_y, get_rgba(255, 0, 0, 255));
}

void	get_rays(t_all *all, t_rays	*rays)
{
	int column = 0;
	int	i;
	float	ray_angle;
	// t_rays	rays[NUM_RAYS];
	// start first ray substracting half of the fov
	ray_angle = all->player.rotation_angle - (FOV_ANGLE / 2);
	ray_angle = adjastAngle(ray_angle);
	//fill rays with info
	i = -1;
	while (++i < NUM_RAYS)
	{
		rays[i] = render_ray(all, ray_angle, column, i, rays[i]);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		ray_angle = adjastAngle(ray_angle);
		column++;
	}
	mlx_texture_t *texture = mlx_load_png("./wall.png");
}

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right