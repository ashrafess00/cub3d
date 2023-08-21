/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/21 18:53:07 by aessaoud         ###   ########.fr       */
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

float x_end_f(mlx_texture_t *txt , t_rays ray)
{
    float x_end;
    if (ray.found_ver_wall_hit)
		x_end = (txt->width / TILE_SIZE)
			* ( ray.wall_hit_y - (int)(ray.wall_hit_y / TILE_SIZE) * TILE_SIZE);
	else
		x_end = (txt->width / TILE_SIZE)
			* ( ray.wall_hit_x - (int)(ray.wall_hit_x / TILE_SIZE) * TILE_SIZE);
    return x_end;
}
void for_every_deriction(mlx_texture_t *txt, t_rays ray, t_all *all, float x, float width, float y, float height, float flag)
{
    float x_en = x + width;
    float y_en = y + height;
    int x_end = 0;
    int y_end = 0;
    int fl;
    
    fl = y;
    x_end = x_end_f(txt, ray);
    while (y <= y_en)
    {
        if (y >= WINDOW_HEIGHT)
            break ;
        y_end = (y - fl) * (txt->height / height);
        if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
        {
            y++;
            continue;
        }
        if(flag == 0)
        {
            if (y_end < txt->height)
                mlx_put_pixel(all->mlx_img, x, y,txt_pixel(txt, x_end, y_end));
        }
        else if(flag == 1)
        {
            if (y_end < txt->height)
                mlx_put_pixel(all->mlx_img, x, y,txt_pixel(txt, txt->width - x_end, y_end));
        }
        y++;
    }
}
void draw_walls(t_all *all, t_rays ray, float x, float y, float width, float height, float color)
{
    if(ray.found_horz_wall_hit == 1 && ray.is_ray_facing_down == 1)
        for_every_deriction(all->txt.e_txt, ray, all, x,width, y, height,1);
    else if(ray.found_horz_wall_hit == 1 && ray.is_ray_facing_up == 1)
       for_every_deriction(all->txt.s_txt, ray, all, x,width, y, height,0);
    else if(ray.found_ver_wall_hit == 1 && ray.is_ray_facing_left == 1)
       for_every_deriction(all->txt.w_txt, ray, all, x,width, y, height,1);
    else if(ray.found_ver_wall_hit == 1 && ray.is_ray_facing_right == 1)
        for_every_deriction(all->txt.n_txt, ray, all, x,width, y, height,0);
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
    float     wall_strip_height;
    float     x;
    float     y;
    float     width;
    float     height;

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
        draw_walls(all, rays[i], x, y, width, height,
                        get_rgba(255, 0, 0, 255));
    }
}