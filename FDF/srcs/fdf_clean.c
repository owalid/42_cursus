/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:54:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/09 19:14:39 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_del_map(t_gnl *gnl)
{
	t_gnl *tmp;

	while (gnl)
	{
		tmp = gnl;
		ft_strdel(&(gnl->str));
		gnl = gnl->next;
		ft_memdel((void *)&tmp);
	}
}

void		fdf_del_tab(int **ptr, int size)
{
	int 	i;

	i = -1;
	while (i < size)
		free(ptr[++i]);
	free(ptr);
}

void		fdf_del_info(t_infowin *info)
{
	fdf_del_tab(info->tab, info->h);
	fdf_del_tab(info->ptr, info->h * info->w);
}

void		fdf_del_mlx(t_mlxprint *mlx)
{
	fdf_del_info(mlx->infos);
	ft_memdel(mlx->mlx_ptr);
	ft_memdel(mlx->mlx_win);
	ft_memdel((void*)mlx);
	mlx = NULL;
}

void		fdf_del_all(t_mlxprint *mlx, t_infowin *info, t_gnl *gnl)
{
	fdf_del_map(gnl);
	fdf_del_info(info);
	fdf_del_mlx(mlx);
}
