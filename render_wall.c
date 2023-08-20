/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/20 14:41:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right

void draw_rectangle(t_all *all, t_rays ray, int x, int y, int width, int height, int color) {
    int x_end = x + width;
    int y_end = y + height;
    int i;
    int j;
    
    i = x;
    while (i < x_end)
    {
        j = y;
        while (j < y_end)
        {
            if (i < 0 || i > WINDOW_WIDTH || j < 0 || j > WINDOW_HEIGHT)
            {
                j++;
                continue;
            }
            mlx_put_pixel(all->mlx_img, i, j, color);
            j++;
        }
        i++;
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
                        get_rgba(236, 120, 160, 255));
    }
}