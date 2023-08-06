#include "Cub3dHeader.h"

int main(int c, char **args)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "BOSA FL FMM KHAYRON MINA DONYA WAMA FIHA");
	mlx_loop(mlx);
}