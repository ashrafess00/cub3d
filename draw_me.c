/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:44 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/15 10:53:35 by aessaoud         ###   ########.fr       */
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
    // center_x *= MINIMAP_SCALE_FACTOR;
    // center_y *= MINIMAP_SCALE_FACTOR;
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


static int	get_steps(int dx, int dy)
{
	if (dx > dy)
		return (dx);
	else
		return (dy);
}

void	draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color)
{
    // x1 *= MINIMAP_SCALE_FACTOR;
    // x2 *= MINIMAP_SCALE_FACTOR;
    // y1 *= MINIMAP_SCALE_FACTOR;
    // y2 *= MINIMAP_SCALE_FACTOR;
    
	float	incx;
	float	incy;
	int		steps;
	int		i;
    int dx = x2 - x1;
    int dy = y2 - y1;
    
	steps = get_steps(dx, dy);
	incx = dx / (float) steps;
	incy = dy / (float) steps;
	i = -1;
	while (++i <= steps)
	{
		if (x1 < x2)
			x1 += incx;
		else
			x1 -= incx;
		if (y1 < y2)
			y1 += incy;
		else
			y1 -= incy;
		mlx_put_pixel(mlx_img, (int)round(x1), (int)round(y1), color);
	}
}


// void	draw_line(mlx_image_t *mlx_img, int x1, int y1, int x2, int y2, int color)
// {
// 	int delta_x = abs(x2 - x1);
// 	int delta_y = abs(y2 - y1);
// 	int sign_x = x1 < x2 ? 1 : -1;
// 	int sign_y = y1 < y2 ? 1 : -1;
// 	int error = delta_x - delta_y;


// 	// mlx_put_pixel(data->mlx, data->mlx_win, x2, y2, color);
//     mlx_put_pixel(mlx_img, x2, y2, color);
// 	while (x1 != x2 || y1 != y2) {
// 		mlx_put_pixel(mlx_img, x1, y1, color);
// 		int error2 = error * 2;
// 		if (error2 > -delta_y) {
// 			error -= delta_y;
// 			x1 += sign_x;
// 		}
// 		if (error2 < delta_x) {
// 			error += delta_x;
// 			y1 += sign_y;
// 		}
// 	}
// }

//draw the map
void draw_map(mlx_image_t *mlx_img)
{
    int Map[MAP_ROWS][MAP_COLS] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
                                    
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
					if (Map[i][j] != 0)
                        mlx_put_pixel(mlx_img, j * TILE_SIZE + z, i * TILE_SIZE + u, get_rgba(0, 0, 0, 255));
                    else
                        mlx_put_pixel(mlx_img, j * TILE_SIZE + z, i * TILE_SIZE + u, get_rgba(255, 255, 255, 255));
				}
			}
		}
	}
}

