/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:44 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/18 11:54:03 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

//these two functions are from chatgpt
void draw_player(mlx_image_t *mlx_img, int center_x, int center_y) {
    int x = PLAYER_RADIUS;
    int y = 0;
    int err = 0;

    center_x *= MINIMAP_SCALE_FACTOR;
    center_y *= MINIMAP_SCALE_FACTOR;
    while (x >= y) {
        if (center_y + y < 0 || center_y + x < 0 || center_y - x < 0 || center_y - y < 0)
            return ;
        mlx_put_pixel(mlx_img, center_x + x, center_y + y, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x + y, center_y + x, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x - y, center_y + x, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x - x, center_y + y, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x - x, center_y - y, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x - y, center_y - x, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x + y, center_y - x, PLAYER_COLOR);
        mlx_put_pixel(mlx_img, center_x + x, center_y - y, PLAYER_COLOR);
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
	if (abs(dx) > abs(dy))
		return (abs(dx));
	else
		return (abs(dy));
}

void	draw_line(t_all *all, int x1, int y1, int x2, int y2, int color)
{
    x1 *= MINIMAP_SCALE_FACTOR;
    x2 *= MINIMAP_SCALE_FACTOR;
    y1 *= MINIMAP_SCALE_FACTOR;
    y2 *= MINIMAP_SCALE_FACTOR;
    
	float	incx;
	float	incy;
	int		steps;
	int		i;
    int dx = x2 - x1;
    int dy = y2 - y1;
    
	steps = get_steps(dx, dy);
	incx = dx / (float) steps;
	incy = dy / (float) steps;
    float x = x1;
    float y = y1;
	i = -1;
	while (++i <= steps)
	{
        if (x < 0 || x >= all->map.window_wid || y < 0 || y >= all->map.window_heig)
            return ;
		mlx_put_pixel(all->mlx_img, (int)round(x), (int)round(y), color);
        x += incx;
        y += incy;
    }
}


//draw the map
void draw_map(t_all *all)
{
                                    
    int i = -1;
	while (all->map.pure_map[++i])
	{  
		int j = -1;
		while (all->map.pure_map[i][++j])
		{
            //here we draw the square
			int u = -1;
			while (++u < TILE_SIZE * MINIMAP_SCALE_FACTOR)
			{
				int z = -1;
				while (++z < TILE_SIZE * MINIMAP_SCALE_FACTOR)
				{
					if (all->map.pure_map[i][j] != '0' && all->map.pure_map[i][j] != ' ' )
                        mlx_put_pixel(all->mlx_img, j * TILE_SIZE * MINIMAP_SCALE_FACTOR + z, i * TILE_SIZE * MINIMAP_SCALE_FACTOR + u, get_rgba(0, 0, 0, 255));
                    else
                        mlx_put_pixel(all->mlx_img, j * TILE_SIZE * MINIMAP_SCALE_FACTOR + z, i * TILE_SIZE * MINIMAP_SCALE_FACTOR + u, get_rgba(255, 255, 255, 255));
				}
			}
		}
	}
}

