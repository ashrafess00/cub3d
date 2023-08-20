/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:11:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/19 10:19:18 by kslik            ###   ########.fr       */
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
	}
	else
	{
		rays.wall_hit_x = rays.verWallHitX;
		rays.wall_hit_y = rays.verWallHitY;
		rays.ray_distance = verHitDistance;
	}
	// rays.wall_hit_x = rays.horzWallHitX;
	// rays.wall_hit_y = rays.horzWallHitY;
	rays.ray_distance = rays.ray_distance * cos(rayAngle - all->player.rotation_angle);
	return (rays);
}

void	draw_casts(t_all *all, t_rays *rays)
{
	int	i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		draw_line(all, all->player.x, all->player.y, rays[i].wall_hit_x, rays[i].wall_hit_y, get_rgba(255, 0, 0, 255));
		// printf("up : %d\n", rays[i].is_ray_facing_up);
		// printf("down : %d\n", rays[i].is_ray_facing_down);
		// printf("left : %d\n", rays[i].is_ray_facing_left);
		// printf("right : %d\n", rays[i].is_ray_facing_right);
		// printf("wall_hit_x : %d\n", rays[i].wall_hit_x);
		// printf("wall_hit_y : %d\n\n", rays[i].wall_hit_y);
		// break;
	}
}
void cast_rays(t_all *all)
{
	int column = 0;
	int	i;
	
	t_rays	rays[NUM_RAYS];
	// start first ray substracting half of the fov
	float rayAngle = all->player.rotation_angle - (FOV_ANGLE / 2);
	rayAngle = adjastAngle(rayAngle);
	//fill rays with info
	i = -1;
	printf("hi there : %f\n", all->player.rotation_angle);
	while (++i < NUM_RAYS)
	{
		rays[i] = render_ray(all, rayAngle, column, i, rays[i]);
		rayAngle += (FOV_ANGLE / NUM_RAYS);
		rayAngle = adjastAngle(rayAngle);
		column++;
	}
	// printf("[[%d]]\n", column);
	mlx_texture_t *texture = mlx_load_png("./wall.png");
	//render walls
	i = -1;
	while (++i < NUM_RAYS )
		render_3d_project_walls(all, rays[i], i);
	draw_casts(all, rays);
}

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right