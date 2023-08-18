/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/18 11:48:27 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

//horizontal and verical 
//horizontal -> up and down
//vertical -> left or right
void draw_rectangle(t_all *all, t_rays ray, int x, int y, int width, int height, int color)
{
    // printf("[down : %d]\n", ray.is_ray_facing_down);
    // printf("[up : %d]\n", ray.is_ray_facing_up);
    // printf("[left : %d]\n", ray.is_ray_facing_left);
    // printf("[right : %d]\n", ray.is_ray_facing_right);

    // mlx_texture_t *texture = mlx_load_png("./wall.png");
    if (ray.found_horz_wall_hit)
    {
        if (ray.is_ray_facing_up)
        {
            //////
        }
        else
        {
            //////
        }
    }
    else
    {
        if (ray.is_ray_facing_left)
        {
            ////////
        }
        else
        {
            /////////
        }
    }


    
	int x_end = x + width;
	int y_end = y + height;
    int i = 0;
    int j = 0;
    
    // static int x_end_s = 0;
    // static int y_end_s = 0;
    // static int x_s = 0;
    // static int y_s = 0;
    printf("%d %d\n", x_end, y_end);
    if (x_end >= 0 && x_end <= all->map.window_wid &&
        y_end >=0 && y_end <=  all->map.window_heig && 
        x >= 0 && x <= all->map.window_wid  &&
        y >= 0 && y <=  all->map.window_heig)
    {
        printf("dkhat\n");
        for (int i = x; i < x_end; i++) {
            mlx_put_pixel(all->mlx_img, i, y, color);
            mlx_put_pixel(all->mlx_img, i, y_end - 1, color);
        }

        for (int i = y + 1; i < y_end - 1; i++) {
            mlx_put_pixel(all->mlx_img, x, i, color);
            mlx_put_pixel(all->mlx_img, x_end - 1, i, color);
        }
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
void render_3d_project_walls(t_all *all, t_rays ray, int i)
{
    // printf("{ray distance : %f}\n", ray_distance);
    // calculate the distance to the projection plane

    float distance_projection_plane = (all->map.window_wid / 2) / tan(FOV_ANGLE / 2);
    //projected wall height
    int wall_strip_height = (TILE_SIZE /  ray.ray_distance) * distance_projection_plane;
    //draw rectangle
    int x = i;
    int y = (all->map.window_heig / 2) - (wall_strip_height / 2);
    int width = WALL_STRIP_WIDTH * 2;
    int height = wall_strip_height;
    draw_rectangle(all, ray, x, y, width, height,
                    get_rgba(236, 120, 160, 255));
}