/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:49 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 15:55:19 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HEADER_H
# define CUB3D_HEADER_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "../MLX42/MLX42.h"
# include <math.h>
# define TILE_SIZE 32
# define MAP_COLS 20
# define MAP_ROWS 20
# define WIN_W 640
# define WIN_H 640
# define FOV_ANGLE 1.0471975512
# define WALL_STRIP 1
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS 640
# define MINIMAP_SCALE 0.2
# define PLAYER_RADIUS 10
# define PLAYER_COLOR 16744448
# define FLOAT_EPSILON 1e-5
# define WINDOW_TITLE "GODESS OF BEAUTY"

typedef struct s_player
{
	float	x;
	float	y;
	float	radius;
	float	turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	move_speed;
	float	rotation_speed;
	int		move_side;
	char	*c;
}	t_player;

struct s_rgb
{
	int	f[3];
	int	c[3];	
};
struct s_textures
{
	mlx_texture_t	*s_txt;
	mlx_texture_t	*w_txt;
	mlx_texture_t	*n_txt;
	mlx_texture_t	*e_txt;
};

struct s_txt
{
	char	*so_txt;
	char	*we_txt;
	char	*no_txt;
	char	*ea_txt;
};

struct s_map
{
	char			*first_line;
	char			*whole_map;
	char			**my_map;
	int				index;
	int				char_in_map;
	int				tmp;
	char			**pure_map;
	int				last_line;
	int				win_w;
	int				win_h;
	int				lines;
	struct s_rgb	rgb;
	struct s_txt	txt;
};

typedef struct s_all
{
	t_player			player;
	mlx_t				*mlx;
	mlx_image_t			*mlx_img;
	struct s_map		map;
	struct s_rgb		rgb;
	struct s_textures	txt;
}	t_all;

typedef struct s_intrc_dt
{
	float	x_step;
	float	y_step;
	float	x_intercept;
	float	y_intercept;
}	t_intrc_dt;

struct s_checker
{
	int		i;
	int		jj;
	int		k;
	int		n;
	int		s;
	int		we;
	int		ea;
	int		j;
	int		c;
	int		f;
	int		nmb;
	int		tmp;
	int		comma;
	int		vld;
	char	*q;
};

typedef struct s_rays
{
	float	ray_distance;
	bool	found_horz_wall_hit;
	bool	found_ver_wall_hit;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;
	float	ver_wall_hit_x;
	float	ver_wall_hit_y;
	float	main_wall_hit_x;
	float	main_wall_hit_y;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
}	t_rays;

struct s_wall
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		flag;
	int		fl;
	int		y_end;
	float	y_en;
};
typedef struct s_dda_data
{
	float	x;
	float	y;
	float	incx;
	float	incy;
	int		steps;
	int		i;
	int		dx;
	int		dy;
}	t_dda_data;

typedef struct s_line_cords
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
}	t_line_cords;

int			checker_1(char **args);
void		init_check(struct s_checker *check, int i);
void		while_check(struct s_map *map, struct s_checker *che, int i);
int			is_player(char *s, int i);
void		draw_walls(t_all *all, t_rays ray, struct s_wall *wall);
void		werror(int i);
int			check_mty_line(struct s_map *map, int start);
int			checker_2(struct s_map *map);
int			checker_1(char **args);
int			exctract(struct s_map *map, t_player *player, int ma, int j);
int			get_rgba(int r, int g, int b, int a);
void		draw_player(t_all *all);
void		press_key(mlx_key_data_t keydata, void *param);
void		move_mouse(double xpos, double ypos, void *param);
void		draw_update_all(t_all *all);
int			checker_map(struct s_map *map, int ply, int j);
int			check_valid(struct s_map *map);
void		get_rays(t_all *all, t_rays	*rays);
bool		in_the_wall(float x, float y, t_all *all);
float		adjast_angle(float ray_angle);
float		get_angle_for_play(t_player *player);
int			get_wi_he(struct s_map *map);
void		draw_update_all(t_all *all);
void		for_every_deriction(mlx_texture_t *txt, t_rays ray,
				t_all *all, struct s_wall *wall);
void		init_player(t_player *player, t_all *all);
void		horizontal_intersection(t_all *all, float ray_angle, t_rays *ray);
void		vertical_intersection(t_all *all, float ray_angle, t_rays *ray);
float		distance_between_points(float x1, float y1, float x2, float y2);
void		render_3d_project_walls(t_all *all, t_rays *rays);
uint32_t	txt_pixel(mlx_texture_t *texture, int x, int y);
int			extract_2(struct s_map *map, int start);
int			x_end_f(mlx_texture_t *txt, t_rays ray);
t_rays		fill_ray_direction(t_rays ray, float ray_angle);
void		init_player(t_player *player, t_all *all);
void		init_mlx(t_all *all);

//free
void		free_exit(t_all *all);

//init
void		init_map(t_all *all, t_player *player, char *file);

//textures
int			load_text_n(struct s_map *map, int i, int j);
int			load_text_s(struct s_map *map, int i, int j);
int			load_text_e(struct s_map *map, int i, int j);
int			load_text_w(struct s_map *map, int i, int j);
#endif