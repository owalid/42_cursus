/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:58:50 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 18:49:00 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl_op.h"

void		frtl_init_img(t_infowin *window, t_img *img, void *mlx_ptr)
{
	img->size_line = 0;
	img->bperpix = 0;
	img->mlx_img = mlx_new_image(mlx_ptr, window->width, window->height);
	img->data = (int *)mlx_get_data_addr(img->mlx_img, &img->bperpix, &img->size_line, &img->endian);
}

void		frtl_graph(t_mlx *mlx)
{
	t_frtl	frtl[1];
	t_img	img[1];

	frtl_init_img(mlx->infos, img, mlx->mlx_ptr);
	mlx->infos->img = img;
	frtl_init(mlx, frtl);
	mlx->frtl = frtl;
	g_frtlop[mlx->infos->frtl].frtl_dspl(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->infos->img->mlx_img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->infos->img->mlx_img);
}

void		wind_init(t_infowin *infos)
{
	t_mlx	mlx[1];

	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, infos->width, infos->height, "Fractol");
	mlx->infos = infos;
	frtl_graph(mlx);
	mlx_hook(mlx->mlx_win, 2, 5, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
