/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windows_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:07:08 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/09 18:19:34 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_initimg(t_infowin *infos, t_img *img, void *mlx_ptr)
{
	img->mlx_img = mlx_new_image(mlx_ptr, infos->width, infos->height);
	img->data = (int *)mlx_get_data_addr(img->mlx_img, &img->bperpix,
			&img->size_line, &img->endian);
}

int			iso_expression(int i, int j, t_mlxprint *mlx, int option)
{
	int		z;

	z = mlx->infos->tab[i][j];
	if (option == 1)
		return (((i * cos(mlx->a) * mlx->zoom + j *
						cos(mlx->a + mlx->xorientation) * mlx->zoom + z
						* mlx->relief * cos(mlx->a - mlx->xorientation)
						* mlx->zoom / 30 * mlx->h) + (mlx->infos->height / 4))
				+ mlx->infos->ymove * 50);
	else
		return (((i * sin(mlx->a) * mlx->zoom + j *
						sin(mlx->a + mlx->yorientation) * mlx->zoom
						+ z * mlx->relief * sin(mlx->a - mlx->yorientation)
						* mlx->zoom / 30 * mlx->h)
					+ (mlx->infos->width / 2.25)) + mlx->infos->xmove * 50);
}

int			**transform_tab(t_mlxprint *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < mlx->infos->h)
	{
		j = 0;
		while (j < mlx->infos->w)
		{
			mlx->infos->ptr[k][0] = iso_expression(i, j, mlx, 1);
			mlx->infos->ptr[k][1] = iso_expression(i, j, mlx, 0);
			j++;
			k++;
		}
		i++;
	}
	return (mlx->infos->ptr);
}

void		fdf_graph(t_mlxprint *mlx)
{
	t_img	img[1];

	fdf_initimg(mlx->infos, img, mlx->mlx_ptr);
	mlx->infos->img = img;
	transform_tab(mlx);
	display_all(mlx->infos->ptr, mlx->infos);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->infos->img->mlx_img, 0, 0);
	display_usage(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx_ptr, mlx->infos->img->mlx_img);
}

void		fdf_init(t_infowin *info)
{
	t_mlxprint	mlx[1];

	mlx->egg = 0;
	mlx->mlx_orient_max = 0;
	mlx->vpress = 0;
	mlx->stoplooph = 0;
	mlx->relief = 1;
	mlx->zoom = 25;
	info->xmove = 0;
	info->ymove = 0;
	mlx->yorientation = 2;
	mlx->xorientation = 2;
	mlx->a = -1;
	mlx->h = 2;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr,
			info->width, info->height, "fdf");
	mlx->infos = info;
	fdf_init_tab(info);
	fdf_graph(mlx);
	mlx_hook(mlx->mlx_win, 2, 5, deal_key, mlx);
	mlx_loop_hook(mlx->mlx_ptr, loop_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
}
