/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 12:14:36 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	werror(int i)
{
	if (i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

void	load_txt(struct s_map *map, struct s_all *all)
{
	all->txt.s_txt = mlx_load_png(map->txt.so_txt);
	all->txt.w_txt = mlx_load_png(map->txt.we_txt);
	all->txt.n_txt = mlx_load_png(map->txt.no_txt);
	all->txt.e_txt = mlx_load_png(map->txt.ea_txt);
	if (!(all->txt.s_txt && all->txt.w_txt && all->txt.n_txt && all->txt.e_txt))
	{
		if (all->txt.s_txt)
			mlx_delete_texture(all->txt.s_txt);
		if (all->txt.w_txt)
			mlx_delete_texture(all->txt.w_txt);
		if (all->txt.n_txt)
			mlx_delete_texture(all->txt.n_txt);
		if (all->txt.e_txt)
			mlx_delete_texture(all->txt.e_txt);
		werror(1);
	}
	free(map->txt.so_txt);
	free(map->txt.no_txt);
	free(map->txt.we_txt);
	free(map->txt.ea_txt);
}
void	count_line(struct s_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->whole_map[i] != '\0')
	{
		if (map->whole_map[i] == '\n')
			j++;
		i++;
	}
	map->lines = j;
}
void	init_map(t_all *all, t_player *player, char *file)
{
	struct s_map	map;
	int				fd;
	char			s[120];

	map.tmp = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		werror(1);
	while (map.tmp != 0)
	{
		map.tmp = read(fd, s, 100);
		map.char_in_map += map.tmp;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	map.whole_map = ft_calloc(map.char_in_map + 1, 1);
	map.index = read(fd, map.whole_map, map.char_in_map);
	count_line(&map);
	map.my_map = ft_split(map.whole_map, '\n');
	checker_2(&map);
	exctract(&map, player, 0,0);
	load_txt(&map, all);
	all->map = map;
	all->rgb = map.rgb;
}
void	free_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
}
void	free_exit(t_all *all)
{
	if (all->txt.s_txt)
		mlx_delete_texture(all->txt.s_txt);
	if (all->txt.w_txt)
		mlx_delete_texture(all->txt.w_txt);
	if (all->txt.n_txt)
		mlx_delete_texture(all->txt.n_txt);
	if (all->txt.e_txt)
		mlx_delete_texture(all->txt.e_txt);
	if (all->map.my_map)
		free(all->map.my_map);
	if (all->map.whole_map)
		free(all->map.whole_map);
	if (all->map.pure_map)
		free_double(all->map.pure_map);
	free(all->player.c);
}

// typedef enum mouse_mode
// {
// 	MLX_MOUSE_NORMAL	= 0x00034001,
// 	MLX_MOUSE_HIDDEN	= 0x00034002,
// 	MLX_MOUSE_DISABLED	= 0x00034003,
// }	mouse_mode_t;

void 	move_mouse(double xpos, double ypos, void* param)
{
	t_all			*all;
	static double	p_xpos = 0;
	
	all = param;
	if (xpos >= 0 && xpos < WIN_W && ypos >= 0 && ypos < WIN_H)
	{
		if (xpos > p_xpos)
			all->player.turn_direction += 0.3;
		else
			all->player.turn_direction -= 0.3;
		p_xpos = xpos;
	draw_update_all(all);
	}
	all->player.turn_direction = 0;
}

int	main(int c, char **args)
{
	t_all		all;
	t_player	player;

	if (c != 2 || checker_1(args) == -1)
		werror(1);
	init_map(&all, &player, args[1]);
	init_mlx(&all);
	init_player(&player, &all);
	mlx_image_to_window(all.mlx, all.mlx_img, 0, 0);
	draw_update_all(&all);
	mlx_key_hook(all.mlx, move_mama, &all);
	mlx_cursor_hook(all.mlx, move_mouse, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	free_exit(&all);
	return (0);
}

//ray casting steps
//1- substract 30 degrees from player rotaion angle fov/2
//2- start at column 0
//3- while(column < 320)
// *cast a ray
// tracet he rau until it intersects with a wall(map[i][j] == 1)
//record the intersection (x, y) and the distance (ray lenght)
//rayAngle += 60 / 320;  (60 will be converted to rad)
////render wall line 46