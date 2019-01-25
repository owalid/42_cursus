/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:26:55 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/25 18:11:44 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void			frtl_pxl(t_mlx *mlx, int x, int  y, unsigned int c)
{
	int 	i;

	i = y * mlx->infos->width + x;
	mlx->infos->img->data[i] = c;
	mlx->infos->img->data[++i] = c >> 8;
	mlx->infos->img->data[++i] =  c >> 16;
}

void			init_tabcolor(t_infowin *infos)
{
	infos->stop_psy = 1;
	infos->color_tab[0] = 0x0BCDEF; 
	infos->color_tab[1] = 0x123456;
	infos->color_tab[2] = 0x110000;
	infos->color_tab[3] = 0x001100;
	infos->color_tab[4] = 0x000011;
	infos->color_tab[5] = 0x111100;
	infos->color_tab[6] = 0xAA00AA;
	infos->color_tab[7] = 0x00AAAA;
	infos->color_tab[8] = 0xFEDCBA;
	infos->color_tab[9] = 0x654321;
	infos->color_tab[10] = 0xAAFFAA;
	infos->color = infos->color_tab[0];
	infos->i_tab = 0;
}

unsigned int	random_color(void)
{
	return (rand() % (((0xFFFF00 + 1) - 0x000000) + 0xFFFFFF));
}
