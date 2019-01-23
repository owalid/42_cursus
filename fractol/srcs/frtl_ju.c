#include "../includes/frtl.h"

void		frtl_iter_ju(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	int		i;

	i = 0;
	frtl->c_r = 0.285;
	frtl->c_i = 0.01;
	frtl->z_r = ((double)x) / frtl->zoom + frtl->x1;
	frtl->z_i = ((double)y) / frtl->zoom + frtl->y1;
	while (frtl->z_r * frtl->z_r + frtl->z_i * frtl->z_i < 4 && i < frtl->i_max)
	{
		frtl->tmp = frtl->z_r;
		frtl->z_r = frtl->z_r * frtl->z_r - frtl->z_i * frtl->z_i + frtl->c_r;
		frtl->z_i = 2 * frtl->tmp * frtl->c_i;
		i++;
	}
	if (i == frtl->i_max)
		frtl_pxl(mlx, x, y, 0x000000);
	else
		frtl_pxl(mlx, x, y, 0x123456 * i);
}

void		frtl_dspl_ju(t_mlx *mlx)
{
	long long x;
	long long y;

	x = 0;
	while (x < mlx->infos->width)
	{
		y = 0;
		while (y < mlx->infos->height)
		{
			frtl_iter_ju(mlx->frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
