/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/10 16:17:38 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_gnl		*get_map(char *file)
{
	int		fd;
	char	*tmp;
	t_gnl	*gnl;

	if ((fd = open(file, O_RDONLY)) == -1)
		fdf_err(2);
	if (get_next_line(fd, &tmp))
	{
		gnl = ft_lstgnlnew(tmp);
		ft_strdel(&tmp);
	}
	else
		fdf_err(3);
	while (get_next_line(fd, &tmp))
	{
		ft_lstgnlpushback(&gnl, tmp);
		ft_strdel(&tmp);
	}
	if (close(fd) == -1)
		fdf_err(2);
	return (gnl);
}

int			*create_tab(char *str, t_infowin *infos)
{
	char	**split_matrix;
	int		*result;
	int		i;

	i = 0;
	split_matrix = ft_strsplit(str, ' ');
	while (split_matrix[i])
		i++;
	if (!(result = (int*)malloc(sizeof(int) * i)))
		fdf_err(2);
	i = -1;
	while (split_matrix[++i])
		result[i] = ft_atoi(split_matrix[i]);
	if (infos->w == 0)
		infos->w = i;
	ft_del_tab(&split_matrix);
	return (result);
}

void		fdf_parser(t_gnl *map, t_infowin *infos)
{
	t_gnl	*tmp;
	int		**tab;
	int		i;

	if (!(tab = (int**)malloc(sizeof(int*) * ft_lstgnlsize(map))))
		fdf_err(2);
	i = -1;
	infos->w = 0;
	tmp = map;
	while (tmp)
	{
		tab[++i] = create_tab(tmp->str, infos);
		tmp = tmp->next;
	}
	if (i == 0)
		fdf_err(2);
	infos->h = i;
	infos->tab = tab;
	infos->color = fdf_random_color();
	fdf_del_map(&map);
}
