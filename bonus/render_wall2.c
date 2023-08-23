/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:27:36 by kslik             #+#    #+#             */
/*   Updated: 2023/08/23 16:03:28 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header_bonus.h"

uint32_t	txt_pixel(mlx_texture_t *texture, int x, int y)
{
	uint32_t	p;

	p = ((uint32_t *)texture->pixels)[texture->width * y + x];
	return ((p & 0xFF000000) >> 24 | (p & 0x00FF0000) >> 8
		| (p & 0x0000FF00) << 8 | (p & 0x000000FF) << 24);
}

int	x_end_f(mlx_texture_t *txt, t_rays ray)
{
	int	x_end;

	if (ray.found_ver_wall_hit)
		x_end = (txt->width / TILE_SIZE) * (ray.main_wall_hit_y
				- ((int)(ray.main_wall_hit_y / TILE_SIZE)) * TILE_SIZE);
	else
		x_end = (txt->width / TILE_SIZE) * (ray.main_wall_hit_x
				- ((int)(ray.main_wall_hit_x / TILE_SIZE)) * TILE_SIZE);
	return (x_end);
}
