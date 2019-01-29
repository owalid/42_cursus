#include "../includes/frtl.h"

int			deal_mouse(int x, int y, t_mlx *mlx)
{
	x = x - mlx->infos->width / 3;
	y = y - mlx->infos->height / 3;
	if (mlx->infos->frtl == 1 && mlx->infos->mouse == 1)
	{
		mlx->frtl->c_r = (double)((double)x / (double)y);
		mlx->frtl->c_i = (double)((double)x / (double)y);
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	frtl_graph(mlx);
	return (0);
}

int 		deal_scroll(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4 || button == 1)
	{
		mlx->frtl->x1 = (((double)mlx->infos->width * 0.001) - mlx->frtl->x1 - (double)x) * 0.001;
		mlx->frtl->y1 = (((double)mlx->infos->height * -0.001) - mlx->frtl->y1 - (double)y) * 0.001;
		mlx->frtl->zoom += 15.5;
	}
	else if (button == 5 || button == 2)
	{
		mlx->frtl->x1 -= x * 0.0001;
		mlx->frtl->y1 -= y * 0.0001;
		mlx->frtl->zoom -= 5.5;
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	frtl_graph(mlx);
	return (0);
}

int			deal_close(int key, t_mlx *mlx)
{
	(void)mlx;
	(void)key;
	frtl_exit(0);
	return (0);
}
