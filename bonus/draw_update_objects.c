/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:53:18 by aessaoud          #+#    #+#             */
/*   Updated: 2023/09/21 09:45:39 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header_bonus.h"

void	draw_c(t_all *all, int i, int j)
{
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			mlx_put_pixel(all->mlx_img, i, j, get_rgba(all->rgb.f[0],
					all->rgb.f[1], all->rgb.f[2], 255));
			i++;
		}
		j++;
	}
}

void	draw_c_f(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < WIN_H / 2)
	{
		i = 0;
		while (i < WIN_W)
		{
			mlx_put_pixel(all->mlx_img, i, j, get_rgba(all->rgb.c[0],
					all->rgb.c[1], all->rgb.c[2], 255));
			i++;
		}
		j++;
	}
	draw_c(all, i, j);
}

void	set_player_data(t_all *all, float *new_player_x, float *new_player_y)
{
	float	move_step;

	all->player.rotation_angle = adjast_angle(all->player.rotation_angle);
	all->player.rotation_angle += all->player.turn_direction
		* all->player.rotation_speed;
	move_step = all->player.walk_direction * all->player.move_speed;
	*new_player_x = all->player.x + cos(all->player.rotation_angle) * move_step;
	*new_player_y = all->player.y + sin(all->player.rotation_angle) * move_step;
	*new_player_x += all->player.move_side * \
		cos(all->player.rotation_angle + M_PI / 2) * all->player.move_speed;
	*new_player_y += all->player.move_side * \
		sin(all->player.rotation_angle + M_PI / 2) * all->player.move_speed;
	if (*new_player_x < 0 || *new_player_x >= all->map.win_w
		|| *new_player_y < 0 || *new_player_y >= all->map.win_h)
		return ;
}

void	draw_update_all(t_all *all)
{
	float	new_player_x;
	float	new_player_y;
	t_rays	rays[NUM_RAYS];

	set_player_data(all, &new_player_x, &new_player_y);
	if (in_the_wall(all->player.x, new_player_y, all)
		&& in_the_wall(new_player_x, all->player.y, all))
		return ;
	if (!in_the_wall(new_player_x, new_player_y, all))
	{
		if (all->player.x + 1)
			all->player.x = new_player_x;
		all->player.y = new_player_y;
	}
	draw_c_f(all);
	get_rays(all, rays);
	render_3d_project_walls(all, rays);
	draw_map(all);
	draw_player(all);
	draw_casts(all, rays);
}
