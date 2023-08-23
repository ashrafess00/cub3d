/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:44:19 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 12:51:10 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	press_it(t_all *all, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		all->player.walk_direction += 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		all->player.walk_direction -= 1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		all->player.turn_direction += 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		all->player.turn_direction -= 1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		all->player.move_side += 1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		all->player.move_side -= 1;
}

void	release_it(t_all *all, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		all->player.walk_direction = 0;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		all->player.walk_direction = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		all->player.turn_direction = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		all->player.turn_direction = 0;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		all->player.move_side = 0;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		all->player.move_side = 0;
}

void	press_key(mlx_key_data_t keydata, void *param)
{
	t_all	*all;

	all = param;
	press_it(all, keydata);
	release_it(all, keydata);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->mlx);
	draw_update_all(all);
}
