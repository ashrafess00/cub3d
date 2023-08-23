/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 11:33:55 by kslik            ###   ########.fr       */
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
#define MAP_COLS 20
#define MAP_ROWS 20
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIP 1
#define WALL_STRIP_WIDTH 1

#define NUM_RAYS (WINDOW_WIDTH)

#define MINIMAP_SCALE_FACTOR 0.1
#define PLAYER_RADIUS 10
#define PLAYER_COLOR 16744448
#define FLOAT_EPSILON 1e-5
#define WINDOW_TITLE "MOLAT LMLWI TAJSID DYAL ILAHAT LJAMAL"
typedef struct s_player
{
	float x;
	float y;
	float radius;
	int		turn_direction;
	int		walk_direction;
	float rotation_angle;
	float move_speed;
	float rotation_speed;
	int	move_side;
	char *c;
}	t_player;

struct s_rgb
{
	int f[3];
	int c[3];	
};
struct s_textures
{
	mlx_texture_t *s_txt;
	mlx_texture_t *w_txt;
	mlx_texture_t *n_txt;
	mlx_texture_t *e_txt;
};

struct s_txt
{
	char *so_txt;
	char *we_txt;
	char *no_txt;
	char *ea_txt;
};
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
	int lines;
	struct s_rgb rgb;
	struct s_txt txt;
};
typedef struct s_all
{
	t_player player;
	mlx_t *mlx;
	mlx_image_t *mlx_img;
	struct s_map map;
	struct s_rgb rgb;
	struct s_textures txt;
}	t_all;

typedef struct s_rays
{
	float		ray_distance;
	
	bool		found_horz_wall_hit;
	bool		found_ver_wall_hit;

	float 		horzWallHitX;
	float		horzWallHitY;
	float		verWallHitX;
	float		verWallHitY;

	float			main_wall_hit_x;
	float			main_wall_hit_y;
	int is_ray_facing_down;
	int is_ray_facing_up;
	int is_ray_facing_left;
	int is_ray_facing_right;
}	t_rays;

int is_player(char *s, int i);
void draw_walls(t_all *all, t_rays ray, float x, float y, float width, float height, int color);
void werror(int i);
int checker_2(struct s_map *map);
int checker_1(char **args);
void draw_map(t_all *all);
int exctract(struct s_map *map, t_player *player);
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y);
int get_rgba(int r, int g, int b, int a);
void	draw_line(t_all *all, int x1, int y1, int x2, int y2, int color);
void move_mama(mlx_key_data_t keydata, void *param);
void draw_update_all(t_all *all);
void	get_rays(t_all *all, t_rays	*rays);
bool in_the_wall(float x, float y, t_all *all);
float adjastAngle(float rayAngle);
int get_wi_he(struct s_map *map);
void draw_update_all(t_all *all);
void	init_player(t_player *player, t_all *all);
void horizontal_intersection(t_all *all, float rayAngle, t_rays *ray);
void vertical_intersection(t_all *all, float rayAngle, t_rays *ray);
float	distance_between_points(float x1, float y1, float x2, float y2);
// float distance_between_points(int x1, int y1, int x2, int y2);
// void render_3d_project_walls(t_all *all, t_rays ray, int i);
void render_3d_project_walls(t_all *all, t_rays *rays);
t_rays fill_ray_direction(t_rays ray, float ray_angle);
int load_text_n(struct s_map *map, int i, int j);
int load_text_s(struct s_map *map, int i, int j);
int load_text_e(struct s_map *map, int i, int j);
int load_text_w(struct s_map *map, int i, int j);
void	draw_casts(t_all *all, t_rays *rays);
void	init_player(t_player *player, t_all *all);
void	init_mlx(t_all *all);

void    put_settings(t_all *all);

#endif