/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:44:19 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/12 10:47:46 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

void move_mama(mlx_key_data_t keydata, void *param)
{
	t_all *all = param;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		all->player.walk_direction += 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		all->player.walk_direction -= 1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		all->player.turn_direction += 1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		all->player.turn_direction -= 1;


	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		all->player.walk_direction = 0;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		all->player.walk_direction = 0;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		all->player.turn_direction = 0;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE )
		all->player.turn_direction = 0;

	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->mlx);

	update_player(all);
	
	// printf("walk directio: %d\n", all->player.walk_direction);
	
	
	if (keydata.key == MLX_KEY_D)
		printf("D\n");
	if (keydata.key == MLX_KEY_LEFT)
		printf("L\n");
	if (keydata.key == MLX_KEY_RIGHT)
		printf("R\n");
}