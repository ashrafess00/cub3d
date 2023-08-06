#include "Cub3dHeader.h"
#define TILE_SIZE 75
#define MAP_ROWS 6
#define MAP_COLS 14
#define WINDOW_WIDTH (TILE_SIZE * MAP_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_ROWS)

int	close_win(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	ft_printf("thank you :), yallah thlla");
	exit(0);
	return (1);
}

void	draw_on_img(t_mlx_data mlx_data, int x, int y, int color)
{
	int		offset;

	offset = y * mlx_data.line_length + x * (mlx_data.bits_per_pixel / 8);
	if (mlx_data.endian == 1)
	{
		mlx_data.addr[offset + 0] = (color >> 16) & 0xff;
		mlx_data.addr[offset + 1] = (color >> 8) & 0xff;
		mlx_data.addr[offset + 2] = (color) & 0xff;
	}
	else
	{
		mlx_data.addr[offset + 0] = (color) & 0xff;
		mlx_data.addr[offset + 1] = (color >> 8) & 0xff;
		mlx_data.addr[offset + 2] = (color >> 16) & 0xff;
	}
}

int main(int c, char **args)
{
	//3ndak tkhl3 rah ghir kantl9 yddi 😪
	int Map[MAP_ROWS][MAP_COLS] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
									{1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
									{1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
									{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
									{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	t_mlx_data mlx_data;
	mlx_data.mlx =  mlx_init();
	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "BOSA FL FMM KHAYRON MINA DONYA WAMA FIHA");
	mlx_data.img = mlx_new_image(mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel, &mlx_data.line_length, &mlx_data.endian);

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
					if (Map[i][j] == 1)
						draw_on_img(mlx_data, j * TILE_SIZE + z, i * TILE_SIZE + u, 0xFFFFFFFF);
					else
						draw_on_img(mlx_data, j * TILE_SIZE + z, i * TILE_SIZE + u, 0x00000000);
				}
			}
		}
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, mlx_data.img, 0 , 0);

	//close window with red x
	mlx_hook(mlx_data.mlx_win, 17, 0, &close_win, &mlx_data);
	mlx_loop(mlx_data.mlx);
}