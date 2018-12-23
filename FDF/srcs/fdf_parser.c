/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/20 22:24:31 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

int		get_size_file(char *file)
{
	int		fd;
	int		size;
	char 	*tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		fdf_err(2);
	size = 0;
	while (get_next_line(fd, &tmp))
	{
		size++;
		free(tmp);
	}
	if (close(fd) != -1)
		fdf_err(2);
	return (size);
}

char		**get_map(char *file)
{
	int 	fd;
	int		i;
	char	**result;

	i = 0;
	if (!(result = (char**)malloc(sizeof(char*) * (get_size_file(file) + 1))))
		fdf_err(2);
	i = 0;
	if ((fd = open(file, O_RDONLY) == -1))
		fdf_err(2);
	while (get_next_line(fd, result + i))
		i++;
	if (close(fd) == 0)
		fdf_err(2);
	result[i] = NULL;
	return (result);
}

int			*create_tab(char *str, t_infowin *infos)
{
	char 	**split_matrix;
	int		*result;
	int		i;

	i = 0;
	split_matrix = ft_strsplit((const char*)str, ' ');
	while (split_matrix[i])
		i++;
	if (!(result = (int*)malloc(sizeof(int) * i)))
		fdf_err(2);
	i = -1;
	while (split_matrix[++i])
		result[i] = ft_atoi(split_matrix[i]);
	if (infos->w == 0)
		infos->w = i;
	//ft_tabfree(split_matrix);
	return (result);
}

void		fdf_parser(char **map, t_infowin *infos)
{
	int 	**tab;
	int		i;

	i = 0;
	while (map[i])
		i++;
	if (!(tab = (int **)malloc(sizeof(int *) * i)))
		fdf_err(2);
	i = -1;
	infos->w = 0;
	while (map[++i])
		tab[i] = create_tab(map[i], infos);
	if (i == 0)
		fdf_err(1);
	infos->h = i;
	infos->tab = tab;
}
