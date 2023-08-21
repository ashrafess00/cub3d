/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/21 13:00:38 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right

uint32_t	txt_pixel(mlx_texture_t *texture, int x, int y)
{
	uint32_t	p;

	p = ((uint32_t *)texture->pixels)[texture->width * y + x];
	return ((p & 0xFF000000) >> 24 | (p & 0x00FF0000) >> 8
		| (p & 0x0000FF00) << 8 | (p & 0x000000FF) << 24);
}
int x_end_f(mlx_texture_t *txt , t_rays ray)
{
    int x_end;
    if (ray.found_ver_wall_hit)
		x_end = (txt->width / TILE_SIZE)
			* ( ray.wall_hit_y - (ray.wall_hit_y / TILE_SIZE) * TILE_SIZE);
	else
		x_end = (txt->width / TILE_SIZE)
			* ( ray.wall_hit_x - (ray.wall_hit_x / TILE_SIZE) * TILE_SIZE);
    return x_end;
}
void draw_rectangle(t_all *all, t_rays ray, int x, int y, int width, int height, int color) 
{
    int x_en = x + width;
    int y_en = y + height;
    int x_end = x + width;
    int y_end = y + height;
    int i;
    int j;
    int fl;
    
//--------

    x_end = x_end_f(all->txt.n_txt, ray);
//--------
    i = x;
    fl = y;
        while (j < y_en)
        {
            if (fl >= WINDOW_HEIGHT)
			    break ;
            y_end = (j - fl) * (all->txt.n_txt->height / height);
            if (i < 0 || i > WINDOW_WIDTH || j < 0 || j > WINDOW_HEIGHT)
            {
                j++;
                continue;
            }        
            if (y_end < all->txt.n_txt->height)
                mlx_put_pixel(all->mlx_img, i, j, txt_pixel(all->txt.n_txt,x_end, y_end));
            j++;
        }
}

/*
   actual wall height              projected wall height
----------------------- = -------------------------------------------
    distance to wall         distance from player to project plane

actuall wall height                = TAIL_SIZE
distance to wall                   = ray distance
distance from player to proj.plane = adjacent = (win_w / 2) / tan(30)
*/
void render_3d_project_walls(t_all *all, t_rays *rays)
{
    // printf("{ray distance : %f}\n", ray_distance);
    // calculate the distance to the projection plane
    float   distance_projection_plane;
    int     wall_strip_height;
    int     x;
    int     y;
    int     width;
    int     height;

    int i = -1;
    while (++i < NUM_RAYS)
    {
        distance_projection_plane = (WINDOW_HEIGHT / 2) / tan(FOV_ANGLE / 2);
        //projected wall height
        wall_strip_height = (TILE_SIZE /  rays[i].ray_distance) * distance_projection_plane;
        //draw rectangle
        x = i;
        y = (WINDOW_WIDTH / 2) - (wall_strip_height / 2);
        width =  2;
        height = wall_strip_height;
        draw_rectangle(all, rays[i], x, y, width, height,
                        get_rgba(255, 0, 0, 255));
    }
}