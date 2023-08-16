/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 12:43:26 by aessaoud         ###   ########.fr       */
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
#define MAP_COLS 24
#define MAP_ROWS 24
#define WINDOW_WIDTH (TILE_SIZE * MAP_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_ROWS)
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIP 1
#define WALL_STRIP_WIDTH 1

#define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP)

#define MINIMAP_SCALE_FACTOR 0.2
#define PLAYER_RADIUS 10
#define PLAYER_COLOR 16744448

#define WINDOW_TITLE "MI AMORE"
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

struct s_map
{
	char *first_line;
	char *whole_map;
	char **my_map;
	int index;
	int char_in_map;
	int tmp;
	char **pure_map;
	int last_line;
	int window_wid;
	int window_heig;
};

typedef struct s_all
{
	t_player player;
	mlx_t *mlx;
	mlx_image_t *mlx_img;
	struct s_map map;
}	t_all;

typedef struct s_rays
{
	float	ray_distance;
	int		wall_hit_x;
	int		wall_hit_y;
	int		found_horz_wall_hit;
	int		found_ver_wall_hit;

	int 	horzWallHitX;
	int		horzWallHitY;
	int		verWallHitX;
	int		verWallHitY;
}	t_rays;

void werror(int i);
int checker_2(struct s_map *map);
int checker_1(char **args);
void draw_map(t_all *all);
int exctract(struct s_map *map);
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y);
int get_rgba(int r, int g, int b, int a);
void	draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color);
void move_mama(mlx_key_data_t keydata, void *param);
void draw_update_all(t_all *all);
void cast_rays(t_all *all);
bool in_the_wall(int x, int y, t_all *all);
float adjastAngle(float rayAngle);
void render_3d_project_walls(mlx_image_t *mlx_img, float ray_distance, int i);
int get_wi_he(struct s_map *map);
void draw_update_all(t_all *all);

bool is_ray_facing_down(float ray_angle);
bool is_ray_facing_up(float ray_angle);
bool is_ray_facing_right(float ray_angle);
bool is_ray_facing_left(float ray_angle);
void horizontal_intersection(t_all *all, float rayAngle, t_rays *ray);
void vertical_intersection(t_all *all, float rayAngle, t_rays *ray);
float distance_between_points(int x1, int y1, int x2, int y2);
#endif