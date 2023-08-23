/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:50:39 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 16:03:33 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header_bonus.h"

static void	init_ray_values(t_rays *ray)
{
	ray->found_ver_wall_hit = 0;
	ray->ver_wall_hit_x = 0;
	ray->ver_wall_hit_y = 0;
}

//calculate the increment x_step and y_step
static void	set_x_y_step(t_rays *ray, t_intrc_dt *intrc_dt, float ray_angle)
{
	intrc_dt->x_step = TILE_SIZE;
	if (ray->is_ray_facing_left)
		intrc_dt->x_step *= -1;
	intrc_dt->y_step = TILE_SIZE * tan(ray_angle);
	if ((ray->is_ray_facing_up && intrc_dt->y_step > 0)
		|| (ray->is_ray_facing_down && intrc_dt->y_step < 0))
		intrc_dt->y_step *= -1;
}

static void	find_the_interception(t_all *all, t_rays *ray, t_intrc_dt intrc_dt)
{
	float	x_to_check;
	float	y_to_check;

	while (intrc_dt.x_intercept >= 0 && intrc_dt.x_intercept <= all->map.win_w
		&& intrc_dt.y_intercept >= 0 && intrc_dt.y_intercept <= all->map.win_h)
	{
		y_to_check = intrc_dt.y_intercept;
		if (ray->is_ray_facing_left)
			x_to_check = intrc_dt.x_intercept - 1;
		else
			x_to_check = intrc_dt.x_intercept;
		if (in_the_wall(x_to_check, y_to_check, all))
		{
			ray->found_ver_wall_hit = 1;
			ray->ver_wall_hit_x = intrc_dt.x_intercept;
			ray->ver_wall_hit_y = intrc_dt.y_intercept;
			break ;
		}
		else
		{
			intrc_dt.x_intercept += intrc_dt.x_step;
			intrc_dt.y_intercept += intrc_dt.y_step;
		}
	}
}

void	vertical_intersection(t_all *all, float ray_angle, t_rays *ray)
{
	t_intrc_dt	intrc_dt;

	init_ray_values(ray);
	*ray = fill_ray_direction(*ray, ray_angle);
	intrc_dt.x_intercept = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		intrc_dt.x_intercept += TILE_SIZE;
	intrc_dt.y_intercept = all->player.y
		+ (intrc_dt.x_intercept - all->player.x) * tan(ray_angle);
	set_x_y_step(ray, &intrc_dt, ray_angle);
	find_the_interception(all, ray, intrc_dt);
}
