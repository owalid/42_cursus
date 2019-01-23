#include "../includes/frtl.h"

void			frtl_pxl(t_mlx *mlx, int x, int  y, unsigned int c)
{
	int 	i;

	i = y * mlx->infos->width + x;
	mlx->infos->img->data[i] = c;
	mlx->infos->img->data[++i] = c >> 8;
	mlx->infos->img->data[++i] =  c >> 16;
}
