/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 11:18:52 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

//from chatgpt
void draw_rectangle(mlx_image_t *mlx_img, int x, int y, int width, int height, int color)
{
	int x_end = x + width;
	int y_end = y + height;

	for (int i = x; i < x_end; i++) {
		mlx_put_pixel(mlx_img, i, y, color);
		mlx_put_pixel(mlx_img, i, y_end - 1, color);
	}

	for (int i = y + 1; i < y_end - 1; i++) {
		mlx_put_pixel(mlx_img, x, i, color);
		mlx_put_pixel(mlx_img, x_end - 1, i, color);
	}
}

void render_3d_project_walls(t_all *all, float ray_distance, int i)
{
    printf("{ray distance : %f}\n", ray_distance);

    // calculate the distance to the projection plane
    float distance_projection_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
    //projected wall height
    int wall_strip_height = (TILE_SIZE /  ray_distance) * distance_projection_plane;
    if (wall_strip_height >= WINDOW_HEIGHT)
        return;
    draw_rectangle(all->mlx_img, i * WALL_STRIP_WIDTH,
                    (WINDOW_HEIGHT / 2) - (wall_strip_height / 2),
                    WALL_STRIP_WIDTH,
                    wall_strip_height,
                    get_rgba(all->rgb.f[0],all->rgb.f[1],all->rgb.f[2], 255));
}