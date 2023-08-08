/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:44 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/07 19:17:39 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

// void	draw_on_img(t_mlx_data mlx_data, int x, int y, int color)
// {
// 	int		offset;

// 	offset = y * mlx_data.line_length + x * (mlx_data.bits_per_pixel / 8);
// 	if (mlx_data.endian == 1)
// 	{
// 		mlx_data.addr[offset + 0] = (color >> 16) & 0xff;
// 		mlx_data.addr[offset + 1] = (color >> 8) & 0xff;
// 		mlx_data.addr[offset + 2] = (color) & 0xff;
// 	}
// 	else
// 	{
// 		mlx_data.addr[offset + 0] = (color) & 0xff;
// 		mlx_data.addr[offset + 1] = (color >> 8) & 0xff;
// 		mlx_data.addr[offset + 2] = (color >> 16) & 0xff;
// 	}
// }

// //these two functions are from chatgpt
// static void draw_line(t_mlx_data mlx_data, int x1, int y1, int x2, int y2, int color)
// {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1)
//     {
//         draw_on_img(mlx_data, x1, y1, color);

//         if (x1 == x2 && y1 == y2)
//             break;

//         int e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }

// void draw_player(t_mlx_data mlx_data, int center_x, int center_y, int radius, int color)
// {
//     int x = 0;
//     int y = radius;
//     int d = 1 - radius;

//     while (y >= x)
//     {
//         draw_line(mlx_data, center_x + x, center_y + y, center_x - x, center_y + y, color);
//         draw_line(mlx_data, center_x + y, center_y + x, center_x - y, center_y + x, color);
//         draw_line(mlx_data, center_x + x, center_y - y, center_x - x, center_y - y, color);
//         draw_line(mlx_data, center_x + y, center_y - x, center_x - y, center_y - x, color);

//         if (d < 0)
//             d += 2 * x + 3;
//         else
//         {
//             d += 2 * (x - y) + 5;
//             y--;
//         }
//         x++;
//     }
// }


// //draw the map
// void draw_map(t_mlx_data mlx_data)
// {
//     int Map[MAP_ROWS][MAP_COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
// 									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
// 									{1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
// 									{1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
// 									{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
// 									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
                                    
//     int i = -1;
// 	while (++i < MAP_ROWS)
// 	{
// 		int j = -1;
// 		while (++j < MAP_COLS)
// 		{
// 			int u = -1;
// 			while (++u < TILE_SIZE)
// 			{
// 				int z = -1;
// 				while (++z < TILE_SIZE)
// 				{
// 					if (Map[i][j] == 1)
// 						draw_on_img(mlx_data, j * TILE_SIZE + z, i * TILE_SIZE + u, 0xFFFFFFFF);
// 					else
// 						draw_on_img(mlx_data, j * TILE_SIZE + z, i * TILE_SIZE + u, 0x00000000);
// 				}
// 			}
// 		}
// 	}
// }