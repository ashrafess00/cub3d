/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 13:27:52 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	put_texture(mlx_texture_t *txt, t_all *all, struct s_wall *wall,
		int x_end)
{
	while (wall->y < wall->y_en)
	{
		if (wall->y >= WIN_H)
			break ;
		wall->y_end = (wall->y - wall->fl) * (txt->height / wall->height);
		if (wall->x < 0 || wall->x >= WIN_W || wall->y < 0 || wall->y >= WIN_H)
		{
			wall->y++;
			continue ;
		}
		if (wall->flag == 0)
		{
			if (wall->y_end < txt->height)
				mlx_put_pixel(all->mlx_img, wall->x, wall->y, txt_pixel(txt,
						x_end, wall->y_end));
		}
		else if (wall->flag == 1)
		{
			if (wall->y_end < txt->height)
				mlx_put_pixel(all->mlx_img, wall->x, wall->y, txt_pixel(txt,
						txt->width - x_end, wall->y_end));
		}
		wall->y++;
	}
}

void	for_every_deriction(mlx_texture_t *txt, t_rays ray, t_all *all,
		struct s_wall *wall)
{
	float	x_en;
	float	y_en;
	int		x_end;
	int		y_end;
	int		fl;

	x_en = wall->x + wall->width;
	y_en = wall->y + wall->height;
	x_end = 0;
	y_end = 0;
	fl = wall->y;
	wall->fl = fl;
	x_end = x_end_f(txt, ray);
	wall->y_end = y_end;
	wall->y_en = y_en;
	put_texture(txt, all, wall, x_end);
}

void	draw_walls(t_all *all, t_rays ray, struct s_wall *wall)
{
	if (ray.found_horz_wall_hit == 1 && ray.is_ray_facing_down == 1)
	{
		wall->flag = 1;
		for_every_deriction(all->txt.s_txt, ray, all, wall);
	}
	else if (ray.found_horz_wall_hit == 1 && ray.is_ray_facing_up == 1)
	{
		wall->flag = 0;
		for_every_deriction(all->txt.n_txt, ray, all, wall);
	}
	else if (ray.found_ver_wall_hit == 1 && ray.is_ray_facing_left == 1)
	{
		wall->flag = 1;
		for_every_deriction(all->txt.w_txt, ray, all, wall);
	}
	else if (ray.found_ver_wall_hit == 1 && ray.is_ray_facing_right == 1)
	{
		wall->flag = 0;
		for_every_deriction(all->txt.e_txt, ray, all, wall);
	}
}

void	render_3d_project_walls(t_all *all, t_rays *rays)
{
	float			distance_projection_plane;
	int				wall_strip_height;
	struct s_wall	wall;
	int				i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		distance_projection_plane = (WIN_H / 2) / tan(FOV_ANGLE / 2);
		wall_strip_height = (TILE_SIZE / rays[i].ray_distance)
			* distance_projection_plane;
		wall.x = i;
		wall.y = (WIN_W / 2) - (wall_strip_height / 2);
		wall.width = 2;
		wall.height = wall_strip_height;
		draw_walls(all, rays[i], &wall);
	}
}
