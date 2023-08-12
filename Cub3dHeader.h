/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3dHeader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/11 18:33:53 by kslik            ###   ########.fr       */
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
#define K_KEY 13
#define S_key 1
#define A_KEY 0
#define D_KEY 2
#define UP_KEY 126
#define DOWN_KEY 125
#define LEFT_KEY 123
#define RIGHT_KEY 124
#define ESC_KEY	256
#define READING 10000000

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

struct s_map
{
	char *first_line;
	char *whole_map;
	char **my_map;
	int index;
	int char_in_map;
	int tmp;
};
void werror(int i);
int checker_2(struct s_map *map);
int checker_1(char **args);
void draw_map(mlx_image_t *mlx_img);
int checker_3(struct s_map *map);
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y, int radius, int color);
int get_rgba(int r, int g, int b, int a);
void	draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color);
// void	draw_on_img(t_mlx_data mlx_data, int x, int y, int color);
// int	close_win(t_mlx_data *mlx_data);
// int	move(int key, t_mlx_data *mlx_data);

#endif