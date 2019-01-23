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
	frtl->zoom = 100;
}

void		frtl_init_ju(t_frtl *frtl)
{

	frtl->i_max = 150;
	frtl->x1 = -1;
	frtl->x2 = 1;
	frtl->y1 = -1.2;
	frtl->y2 = 1.2;
	frtl->tmp = 0;
	frtl->zoom = 150;
}

void		frtl_init(t_mlx *mlx, t_frtl *frtl)
{
	if (mlx->infos->frtl == 0)
		frtl_init_mand(frtl);
	else if (mlx->infos->frtl == 1)
		frtl_init_ju(frtl);
}
