/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:50:35 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 12:53:34 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void	move_mouse(double xpos, double ypos, void *param)
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
