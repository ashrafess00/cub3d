/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 13:35:34 by aessaoud         ###   ########.fr       */
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
