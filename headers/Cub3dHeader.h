#ifndef CUB3DHEADER_H
#define CUB3DHEADER_H

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"

typedef struct s_mlx_data
{
    void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int line_length;
	int bits_per_pixel;
	int endian;
}   t_mlx_data;

#endif