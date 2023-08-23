/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:52:23 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/23 16:03:12 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header_bonus.h"

static void	free_double(char **s)
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
