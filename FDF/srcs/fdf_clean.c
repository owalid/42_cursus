/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:54:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/10 16:18:07 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_del_map(t_gnl **gnl)
{
	if (*gnl)
	{
		fdf_del_map(&((*gnl)->next));
		ft_strdel(&((*gnl)->str));
		free(*gnl);
		*gnl = NULL;
	}
}

void		fdf_del_tab(int **ptr, int size)
{
	int		i;

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
