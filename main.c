/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/20 16:33:27 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void werror(int i)
{
	if(i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void init_mlx(t_all *all)
{

}

void load_txt(struct s_map *map, struct s_textures *text)
{
	text->s_txt = mlx_load_png(map->txt.so_txt);
	text->w_txt = mlx_load_png(map->txt.we_txt);
	text->n_txt = mlx_load_png(map->txt.no_txt);
	text->e_txt = mlx_load_png(map->txt.ea_txt);
	if(!(text->s_txt && text->w_txt && text->n_txt && text->e_txt))
		werror(1);
}

void	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		werror(1);
	}
		
}
int main(int c, char **args)
{
	struct s_map	map;
	int				fd;
	char			s[120];
	int				i;
	t_all			all;
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;
	struct s_textures text;

	if(c != 2 || checker_1(args) == -1)
		werror(1);
	map.tmp = 1;
	fd = open(args[1], O_RDONLY);
	if(fd < 0)
		werror(1);
	while(map.tmp != 0)
	{
		map.tmp = read(fd, s, 100);
		map.char_in_map += map.tmp;
	}
	close(fd);
	fd = open(args[1], O_RDONLY);
	map.whole_map = ft_calloc(map.char_in_map + 1, 1);
	map.index = read(fd, map.whole_map, map.char_in_map);
	map.my_map = ft_calloc(1, 1);
	map.my_map = ft_split(map.whole_map, '\n');
	
	checker_2(&map);
	exctract(&map, &player);
	// load_txt(&map, &text); texture are ready for use but it's off 7ta nbdaw nkhdmo bihum
	
	//////////////////////////////////////////////////////////////////////
	//init mlx window
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, true);
	mlx_img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	all.map = map;
	all.rgb = map.rgb;
	//init player
	init_player(&player, &all);

	all.mlx = mlx;
	all.player = player;
	all.mlx_img = mlx_img;

	//draw all
	mlx_image_to_window(mlx, mlx_img, 0, 0);
	draw_update_all(&all);
	mlx_key_hook(mlx, move_mama, &all);
	mlx_loop(mlx);
	mlx_terminate(mlx);
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