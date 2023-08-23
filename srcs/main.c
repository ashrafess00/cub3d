/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 12:56:01 by aessaoud         ###   ########.fr       */
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
	mlx_key_hook(all.mlx, press_key, &all);
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
//ray_angle += 60 / 320;  (60 will be converted to rad)
////render wall line 46