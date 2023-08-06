#include "Cub3dHeader.h"
#define TILE_SIZE 150
#define MAP_ROWS 4
#define MAP_COLS 4
#define WINDOW_WIDTH (TILE_SIZE * MAP_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_ROWS)

void draw_me()
{

}

void	draw_on_img(char *addr, int line_length, int bits_per_pixel, int endian, int x, int y, int color)
{
	int		offset;

	offset = y * line_length + x * (bits_per_pixel / 8);
	if (endian == 1)
	{
		addr[offset + 0] = (color >> 16) & 0xff;
		addr[offset + 1] = (color >> 8) & 0xff;
		addr[offset + 2] = (color) & 0xff;
	}
	else
	{
		addr[offset + 0] = (color) & 0xff;
		addr[offset + 1] = (color >> 8) & 0xff;
		addr[offset + 2] = (color >> 16) & 0xff;
	}
}

int main(int c, char **args)
{
	//3ndak tkhl3 rah ghir kantl9 yddi 😪
	int Map[4][4] = {{1, 1, 1, 1}, 
					{1, 0, 1, 1},
					{1, 1, 0, 1},
					{1, 1, 1, 1}};

	void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int line_length;
	int bits_per_pixel;
	int endian;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "BOSA FL FMM KHAYRON MINA DONYA WAMA FIHA");
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	// draw_on_img(addr, line_length, bits_per_pixel, endian, 10, 10, 0x00FF0000);
	int i = -1;
	int h = 0;
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
						draw_on_img(addr, line_length, bits_per_pixel, endian, j * TILE_SIZE + z, i * TILE_SIZE + u, 0x00FF0000);
					else
						draw_on_img(addr, line_length, bits_per_pixel, endian, j * TILE_SIZE + z, i * TILE_SIZE + u, 0x00000000);
				}
			}
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0 , 0);
	mlx_loop(mlx);
}