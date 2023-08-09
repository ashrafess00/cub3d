/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/09 21:29:14 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"


int main()
{
	mlx_t *mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT + 100, "al7abs", true);

	
	mlx_texture_t *textrure = mlx_load_png("./kim.png");
	mlx_image_t *mlx_img = mlx_texture_to_image(mlx, textrure);

	mlx_image_to_window(mlx, mlx_img, 0, 0);

	mlx_loop(mlx);
	mlx_delete_image(mlx, mlx_img);
	mlx_delete_texture(textrure);
	mlx_terminate(mlx);
	
}
