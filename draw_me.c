/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:44 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/12 13:18:50 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

//these two functions are from chatgpt
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y, int radius, int color) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        mlx_put_pixel(mlx_img, center_x + x, center_y + y, color);
        mlx_put_pixel(mlx_img, center_x + y, center_y + x, color);
        mlx_put_pixel(mlx_img, center_x - y, center_y + x, color);
        mlx_put_pixel(mlx_img, center_x - x, center_y + y, color);
        mlx_put_pixel(mlx_img, center_x - x, center_y - y, color);
        mlx_put_pixel(mlx_img, center_x - y, center_y - x, color);
        mlx_put_pixel(mlx_img, center_x + y, center_y - x, color);
        mlx_put_pixel(mlx_img, center_x + x, center_y - y, color);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void	draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color)
{
	int delta_x = abs(x2 - x1);
	int delta_y = abs(y2 - y1);
	int sign_x = x1 < x2 ? 1 : -1;
	int sign_y = y1 < y2 ? 1 : -1;
	int error = delta_x - delta_y;

	// mlx_put_pixel(data->mlx, data->mlx_win, x2, y2, color);
    mlx_put_pixel(mlx_img, x2, y2, color);
	while (x1 != x2 || y1 != y2) {
		mlx_put_pixel(mlx_img, x1, y1, color);
		int error2 = error * 2;
		if (error2 > -delta_y) {
			error -= delta_y;
			x1 += sign_x;
		}
		if (error2 < delta_x) {
			error += delta_x;
			y1 += sign_y;
		}
	}
}

//draw the map
void draw_map(mlx_image_t *mlx_img)
{
    int Map[MAP_ROWS][MAP_COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
									{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
									{1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1},
									{1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1},
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
                        mlx_put_pixel(mlx_img, j * TILE_SIZE + z, i * TILE_SIZE + u, get_rgba(0, 0, 0, 255));
                    else
                        mlx_put_pixel(mlx_img, j * TILE_SIZE + z, i * TILE_SIZE + u, get_rgba(255, 255, 255, 255));
				}
			}
		}
	}
}

