#include "../includes/frtl.h"

void		frtl_init_mand(t_frtl *frtl)
{

	frtl->i_max = 100;
	frtl->x1 = -2.1;
	frtl->x2 = 2.1;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->c_i = 0;
	frtl->c_r = 0;
	frtl->z_r = 0;
	frtl->z_i = 0;
	frtl->zoom = 200;
}

void		frtl_init_ju(t_frtl *frtl)
{

	frtl->i_max = 350;
	frtl->x1 = -1;
	frtl->x2 = 1;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->zoom = 300;
}

void		frtl_init_budbrot(t_frtl *frtl)
{
	frtl->i_max = 100;
	frtl->x1 = -2.1;
	frtl->x2 = 0.6;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->zoom = 100;
}
void		frtl_init(t_mlx *mlx, t_frtl *frtl)
{
	if (mlx->infos->frtl == 0)
		frtl_init_mand(frtl);
	else if (mlx->infos->frtl == 1)
		frtl_init_ju(frtl);
	else if (mlx->infos->frtl == 2)
		frtl_init_budbrot(frtl);
}
