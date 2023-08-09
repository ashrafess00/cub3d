/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:44 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/09 13:19:03 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

//these two functions are from chatgpt
static void draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_put_pixel(mlx_img, x1, x2, color);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_player(mlx_image_t *mlx_img, int center_x, int center_y, int radius, int color)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    while (y >= x)
    {
        draw_line(mlx_img, center_x + x, center_y + y, center_x - x, center_y + y, color);
        draw_line(mlx_img, center_x + y, center_y + x, center_x - y, center_y + x, color);
        draw_line(mlx_img, center_x + x, center_y - y, center_x - x, center_y - y, color);
        draw_line(mlx_img, center_x + y, center_y - x, center_x - y, center_y - x, color);

        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}


//draw the map
void draw_map(mlx_image_t *mlx_img)
{
    int Map[MAP_ROWS][MAP_COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
									{1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
									{1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
									{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
                                    
    int i = -1;
	while (++i < MAP_ROWS)
	{
		int j = -1;
		while (++j < MAP_COLS)
		{
			int u = -1;
			while (++u < TILE_SIZE)
			{
				int z = -1;
				while (++z < TILE_SIZE)
				{
					if (Map[i][j] == 1)
                        mlx_put_pixel(mlx_img, j * TILE_SIZE + z, i * TILE_SIZE + u, get_rgba(255, 0, 0, 255));
                    else
                        mlx_put_pixel(mlx_img, j * TILE_SIZE + z, i * TILE_SIZE + u, get_rgba(0, 0, 0, 255));
				}
			}
		}
	}
}

