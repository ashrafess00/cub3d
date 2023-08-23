/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_mcp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:49:53 by kslik             #+#    #+#             */
/*   Updated: 2023/08/23 16:03:07 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header_bonus.h"

int	check_mty_line(struct s_map *map, int start)
{
	int	k;

	k = 0;
	start = 0;
	while (map->whole_map[start] != '\0')
	{
		if (map->whole_map[start] == '1')
			k++;
		else if (map->whole_map[start] != '1' || map->whole_map[start] != ' ')
			k = 0;
		if (k > 4)
		{
			while (map->whole_map[start] != '\0')
			{
				if (map->whole_map[start] == '\n' && (map->whole_map[start
							+ 1] == '\n' || map->whole_map[start + 1] == '\0'))
					werror(1);
				start++;
			}
			return (0);
		}
		start++;
	}
	return (0);
}
