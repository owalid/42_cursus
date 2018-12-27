/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/26 18:08:56 by oel-ayad         ###   ########.fr       */
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
	//printf("\n\n\n%s\n\n", str);
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

unsigned int	fdf_color(int x1, int x2, int y1, int y2)
{
	(void) x1;
	(void) x2;
	(void) y1;
	(void) y2;
	return (0xFF0000);
	/*if (z[i][j] < 0)
		return (0x0000FF);
	if (z[i][j] == 0)
		return (0x00FF00);
	if (z[i][j] >= 1 || z[i][j] <= 20)
		return (0xFFFF00);
	if (z[i][j] >= 21 || z[i][j] <= 60)
		return (0xFFF000);
	if (z[i][j] >= 61 || z[i][j] <= 80)
		return (0xFFD000);
	else
		return (0xFF0000);*/
}
