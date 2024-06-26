/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:44 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 14:49:22 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

static int	get_steps(int dx, int dy)
{
	if (abs(dx) > abs(dy))
		return (abs(dx));
	else
		return (abs(dy));
}

static void	set_x_y(t_all *all, t_line_cords *line_cords)
{
	line_cords->x1 = all->player.x * MINIMAP_SCALE;
	line_cords->y1 = all->player.y * MINIMAP_SCALE;
	line_cords->x2 = (all->player.x + cos(all->player.rotation_angle) * 100) * \
	MINIMAP_SCALE;
	line_cords->y2 = (all->player.y + sin(all->player.rotation_angle) * 100) * \
	MINIMAP_SCALE;
}

void	draw_player(t_all *all)
{
	t_dda_data		dda_data;
	t_line_cords	line_cords;
	int				color;

	set_x_y(all, &line_cords);
	color = get_rgba(170, 200, 250, 255);
	dda_data.dx = line_cords.x2 - line_cords.x1;
	dda_data.dy = line_cords.y2 - line_cords.y1;
	dda_data.steps = get_steps(dda_data.dx, dda_data.dy);
	dda_data.incx = dda_data.dx / (float) dda_data.steps;
	dda_data.incy = dda_data.dy / (float) dda_data.steps;
	dda_data.x = line_cords.x1;
	dda_data.y = line_cords.y1;
	dda_data.i = -1;
	while (++dda_data.i <= dda_data.steps)
	{
		if (dda_data.x < 0 || dda_data.x >= all->map.win_w
			|| dda_data.y < 0 || dda_data.y >= all->map.win_h)
			return ;
		mlx_put_pixel(all->mlx_img, (int)round(dda_data.x),
			(int)round(dda_data.y), color);
		dda_data.x += dda_data.incx;
		dda_data.y += dda_data.incy;
	}
}

static void	draw_square(t_all *all, int i, int j)
{
	int	z;
	int	u;

	u = -1;
	while (++u < TILE_SIZE * MINIMAP_SCALE)
	{
		z = -1;
		while (++z < TILE_SIZE * MINIMAP_SCALE)
		{
			if (all->map.pure_map[i][j] == ' ')
				;
			else if (all->map.pure_map[i][j] != '0' && \
				all->map.pure_map[i][j] != ' '
				&& is_player(all->map.pure_map[i], j) == 0)
				mlx_put_pixel(all->mlx_img, j * TILE_SIZE * MINIMAP_SCALE + z,
					i * TILE_SIZE * MINIMAP_SCALE + u,
					get_rgba(0, 0, 0, 255));
			else
				mlx_put_pixel(all->mlx_img, j * TILE_SIZE * MINIMAP_SCALE + z,
					i * TILE_SIZE * MINIMAP_SCALE + u,
					get_rgba(255, 255, 255, 255));
		}
	}
}

//draw the mini_map
void	draw_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map.pure_map[++i])
	{
		j = -1;
		while (all->map.pure_map[i][++j])
			draw_square(all, i, j);
	}
}
