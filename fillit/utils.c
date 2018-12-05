/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:05:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/05 20:20:38 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_norme(int x, int y, int *x_factor, int *y_factor)
{
	if (x < *x_factor)
		*x_factor = x;
	if (y < *y_factor)
		*y_factor = y;
}

static t_tetri			*coord_factorize(t_tetri *tetri)
{
	int			x_factor;
	int			y_factor;
	int			i;
	t_tetri		*tmp;

	tmp = tetri;
	while (tmp)
	{
		i = -1;
		x_factor = END;
		y_factor = END;
		while (++i < END)
			ft_norme(tmp->point.x[i], tmp->point.y[i], &x_factor, &y_factor);
		i = -1;
		while (++i < END)
		{
			tmp->point.x[i] -= x_factor;
			tmp->point.y[i] -= y_factor;
		}
		tmp = tmp->next;
	}
	return (tetri);
}

static t_tetri			*coord_add(t_tetri *tetri)
{
	int			x;
	int			y;
	int			i;
	t_tetri		*lst;

	i = 0;
	lst = tetri;
	while (lst)
	{
		x = -1;
		i = 0;
		while ((lst->tetri)[++x])
		{
			y = -1;
			while ((lst->tetri)[x][++y] && i <= END)
				if ((lst->tetri)[x][y] == BLOCK)
				{
					lst->point.x[i] = x;
					lst->point.y[i] = y;
					i++;
				}
		}
		lst = lst->next;
	}
	return (coord_factorize(tetri));
}

static t_tetri			*tetri_add(t_tetri *lst, char *line, char c, int op)
{
	t_tetri		*tmp;
	t_tetri		*i;

	i = lst;
	if (!(tmp = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!lst)
		lst = tmp;
	else
	{
		while (i->next)
			i = i->next;
		i->next = tmp;
	}
	tmp->tetri = ft_strsplit(line, '\n');
	tmp->id = c;
	tmp->next = NULL;
	ft_strclr(line);
	if (op)
		lst = coord_add(lst);
	return (lst);
}

t_tetri					*read_file(int fd)
{
	t_tetri	*lst;
	char	*line;
	char	*tmp;
	char	id;
	int		cpt;

	cpt = 0;
	id = 'A';
	lst = NULL;
	tmp = ft_strnew(0);
	while (TRUE)
	{
		if (get_next_line(fd, &line) == 0)
			break ;
		if ((++cpt % 5) != 0 && line[4] != '\n' && line[5] != '\n')
			return (NULL);
		if (line[0] == '\n')
			lst = tetri_add(lst, tmp, id++, 0);
		tmp = ft_strjoinfree(tmp, line, ft_strlen(line), 3);
	}
	if (!lst && !tmp)
		return (NULL);
	lst = tetri_add(lst, tmp, id++, 1);
	ft_memdel((void *)&tmp);
	return (lst);
}
