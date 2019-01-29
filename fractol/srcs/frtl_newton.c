#include "../includes/frtl.h"

void			frtl_iter_new(t_frtl *frtl, t_mlx *mlx, long long x, long long y)
{
	long long 	i;
	double		z_rr;
	double		z_ii;
	double		save_z_r;
	double		save_z_i;

	i = 0;
	frtl->z_r = x / frtl->zoom + frtl->x1;
	frtl->z_i = y / frtl->zoom + frtl->y1;
	save_z_r = frtl->z_r;
	save_z_i = frtl->z_i;
	z_rr = 0;
	z_ii = 0;
	frtl->tmp = 1;
	while (frtl->tmp > 0.0001 && i < frtl->i_max)
	{
		save_z_r = frtl->z_r;
		save_z_i = frtl->z_i;
		z_rr = frtl->z_r * frtl->z_r;
		z_ii = frtl->z_i * frtl->z_i;
		frtl->tmp = z_rr + z_ii * z_ii + z_ii;
		frtl->z_r = (2 * frtl->z_r * frtl->tmp + z_rr - z_ii) / (3 * frtl->tmp);
		frtl->z_i = (2 * frtl->z_i * (frtl->tmp - save_z_r) / (3 * frtl->tmp));
		frtl->tmp = ((frtl->z_r - save_z_r) * (frtl->z_r - save_z_r) + (frtl->z_i - save_z_i) * (frtl->z_i - save_z_i));
		i++;
	}
	if ( frtl->i_max == i || frtl->z_r > 0)
		frtl_pxl(mlx, x, y, mlx->infos->color * i);
	else
	{
		if (frtl->c_r < - 0.3 && frtl->c_i > 0)
			frtl_pxl(mlx, x, y, mlx->infos->color * i + 32);
		else
			frtl_pxl(mlx, x, y, mlx->infos->color * i + 64);
	}
}
void			frtl_dspl_new(t_mlx *mlx)
{
	long long 	x;
	long long 	y;

	x = 0;
	while (x < mlx->frtl->img_x)
	{
		y = 0;
		while (y < mlx->frtl->img_y)
		{
			frtl_iter_new(mlx->frtl, mlx, x, y);
			y++;
		}
		x++;
	}
}
