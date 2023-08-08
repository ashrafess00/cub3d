/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:51:47 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/08 22:57:11 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"


// int	close_win(t_mlx_data *mlx_data)
// {
// 	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
// 	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
// 	ft_printf("thank you :), yallah thlla");
// 	exit(0);
// 	return (1);
// }

int main(int c, char **args)
{
	// //3ndak tkhl3 rah ghir kantl9 yddi 😪
	(void)c;
	(void)args;
	// init mlx
	// t_mlx_data mlx_data;
	// mlx_data.mlx =  mlx_init();
	
	// mlx
	
	// mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "BOSA FL FMM KHAYRON MINA DONYA WAMA FIHA");
	// mlx_data.img = mlx_new_image(mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel, &mlx_data.line_length, &mlx_data.endian);

	// //init player
	// t_player player;
	// player.x = 150;
	// player.y = 150;
	// player.radius = 10;
	// player.turn_direction = 0;
	// player.walk_direction = 0;
	// player.rotation_angle = M_PI / 2;
	// player.move_speed = 3.0;
	// player.rotation_speed = 3 * (M_PI / 180);

	// //draw map
	// draw_map(mlx_data);
	
	// //draw player
	// draw_player(mlx_data, player.x, player.y, player.radius, 0xFF0000);
	// mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, mlx_data.img, 0 , 0);

	// //close window with red x
	// mlx_hook(mlx_data.mlx_win, 17, 0, &close_win, &mlx_data);
	// mlx_key_hook(mlx_data.mlx_win, &move, &mlx_data);
	// mlx_loop(mlx_data.mlx);
}