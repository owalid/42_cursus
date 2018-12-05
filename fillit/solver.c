/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:09:39 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/05 20:17:02 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			delete_tetri(t_tetri *lst, char **tab, int x, int y)
{
	int		i;

	i = -1;
	while (++i < 4)
		tab[x + lst->point.x[i]][y + lst->point.y[i]] = '.';
}

static void			put_tetri(t_tetri *lst, char **tab, int x, int y)
{
	int		i;

	i = -1;
	while (++i < 4)
		tab[x + lst->point.x[i]][y + lst->point.y[i]] = lst->id;
}

static int			is_tetriput(t_tetri *lst, char **tab, int x, int y)
{
	int			i;
	int			size;

	i = -1;
	size = ft_strlen(tab[0]);
	while (++i < 4)
	{
		if (x + lst->point.x[i] >= size || y + lst->point.y[i] >= size)
			return (0);
		if (tab[x + lst->point.x[i]][y + lst->point.y[i]] != '.')
			return (0);
	}
	return (1);
}

int					solv_fillit(t_tetri *tetri, char **tab)
{
	int		x;
	int		y;

	x = 0;
	if (!tetri)
		return (1);
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (is_tetriput(tetri, tab, x, y))
			{
				put_tetri(tetri, tab, x, y);
				if (solv_fillit(tetri->next, tab))
					return (1);
				delete_tetri(tetri, tab, x, y);
			}
			++y;
		}
		++x;
	}
	return (0);
}
