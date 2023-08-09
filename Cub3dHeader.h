/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3dHeader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/09 13:18:18 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DHEADER_H
#define CUB3DHEADER_H

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "MLX42/MLX42.h"
#include <math.h>

#define TILE_SIZE 32
#define MAP_COLS 14
#define MAP_ROWS 6
#define WINDOW_WIDTH (TILE_SIZE * MAP_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_ROWS)
#define K_KEY 13
#define S_key 1
#define A_KEY 0
#define D_KEY 2
#define UP_KEY 126
#define DOWN_KEY 125
#define LEFT_KEY 123
#define RIGHT_KEY 124

typedef struct s_mlx_data
{
    void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int line_length;
	int bits_per_pixel;
	int endian;
}   t_mlx_data;

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

void draw_map(mlx_image_t *mlx_img);
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y, int radius, int color);
int get_rgba(int r, int g, int b, int a);
// void	draw_on_img(t_mlx_data mlx_data, int x, int y, int color);
// int	close_win(t_mlx_data *mlx_data);
// int	move(int key, t_mlx_data *mlx_data);

#endif