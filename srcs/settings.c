/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:58:48 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/22 21:10:04 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

void fill_image_with_color(mlx_image_t *image, uint32_t color)
{
    for (uint32_t y = 0; y < image->height; y++)
    {
        for (uint32_t x = 0; x < image->width; x++)
        {
            // Calculate the pixel index in the pixel array
            uint32_t pixel_index = (y * image->width + x) * 4;

            // Set the pixel color
            image->pixels[pixel_index + 0] = (color >> 16) & 0xFF;
            image->pixels[pixel_index + 1] = (color >> 8) & 0xFF;
            image->pixels[pixel_index + 2] = color & 0xFF;
        }
    }
}

void    put_settings(t_all *all)
{
	mlx_image_t *str;

	str = mlx_put_string(all->mlx, "+ to increse player speed", win_wTH - 200 , 10);
	fill_image_with_color(str, get_rgba(255, 0, 0, 255));
	str = mlx_put_string(all->mlx, "- to increse player speed", win_wTH - 200 , 30);
	fill_image_with_color(str, get_rgba(255, 0, 0, 255));
	// str = mlx_put_string(all->mlx, "1 to increse rotation speed", win_wTH - 200 , 10);
	// fill_image_with_color(str, get_rgba(255, 0, 0, 255));
	// str = mlx_put_string(all->mlx, "2 to increse rotation speed", win_wTH - 200 , 30);
	// fill_image_with_color(str, get_rgba(255, 0, 0, 255));
}