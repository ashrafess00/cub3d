/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3dHeader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/11 15:14:43 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DHEADER_H
#define CUB3DHEADER_H

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "MLX42/MLX42.h"
#include <math.h>

#define TILE_SIZE 60
#define MAP_COLS 14
#define MAP_ROWS 6
#define WINDOW_WIDTH (TILE_SIZE * MAP_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_ROWS)



typedef struct s_player
{
	int x;
	int y;
	int radius;
	int turn_direction;
	int walk_direction;
	float rotation_angle;
	float move_speed;
	float rotation_speed;
}	t_player;

typedef struct s_all {
	t_player player;
	mlx_t *mlx;
	mlx_image_t *mlx_img;
}	t_all;

void draw_map(mlx_image_t *mlx_img);
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y, int radius, int color);
int get_rgba(int r, int g, int b, int a);
void	draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color);
void move_mama(mlx_key_data_t keydata, void *param);
void update_player(t_all *all);
void cast_rays(t_all *all);
#endif