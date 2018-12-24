/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/24 16:44:48 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

t_gnl		*get_map(char *file)
{
	int 	fd;
	char	*tmp;
	t_gnl	*gnl;

	if ((fd = open(file, O_RDONLY)) == -1)
		fdf_err(2);
	if (get_next_line(fd, &tmp))
	{
		gnl = ft_lstgnlnew(tmp);
		free(tmp);
	}
	else
		return (NULL);
	while (get_next_line(fd, &tmp))
	{
		ft_lstgnlpushback(&gnl, tmp);
		free(tmp);
	}
	if (close(fd) == -1)
		fdf_err(2);
	return (gnl);
}

int			*create_tab(char *str, t_infowin *infos)
{
	char 	**split_matrix;
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
	return (result);
}

void		fdf_parser(t_gnl *map, t_infowin *infos)
{
	int 	**tab;
	int		i;

	if (!(tab = (int**)malloc(sizeof(int*) * ft_lstgnlsize(map))))
		fdf_err(2);
	i = -1;
	infos->w = 0;
	while (map)
	{
		tab[++i] = create_tab(map->str, infos);
		map = map->next;
	}
	if (i == 0)
		fdf_err(2);
	infos->h = i;
	infos->tab = tab;
}
