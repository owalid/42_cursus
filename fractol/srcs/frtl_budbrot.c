#include "../includes/frtl.h"

void		frtl_iter_budbrot(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	long long	i;

	i = 0;
	while (frtl->z_r * frtl->z_r + frtl->z_i * frtl->z_i > 4 && i < frtl->i_max)
	{
		frtl->tmp = frtl->z_r;
		frtl->z_r = frtl->z_r * frtl->z_r - frtl->z_i * frtl->z_i + frtl->c_r;
		frtl->z_i = 2 * frtl->z_i * frtl->tmp + frtl->c_i;
		i++;
	}
	if (i == frtl->i_max)
		frtl_pxl(mlx, x, y, 0x000000);
	else
		frtl_pxl(mlx, x, y, 0x123456 * i);
}

void		frtl_dspl_budbrot(t_mlx *mlx)
{
	t_frtl		*frtl;
	long long	x;
	long long	y;

	x = 0;
	frtl = mlx->frtl;
	while (x < mlx->infos->height)
	{
		y = 0;
		while (y < mlx->infos->width)
		{
			frtl->c_r = x / frtl->zoom + frtl->x1;
			frtl->c_i = y / frtl->zoom + frtl->y2; 
			frtl->z_r = 0;
			frtl->z_i = 0;
			frtl_iter_budbrot(frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
