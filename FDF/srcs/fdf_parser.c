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

t_vector	*create_vector(int size_total, int fd)
{
	char		**map_split;
	char		*gnl;
	int			i;
	int			j;
	t_vector	*vector;

	if(!(vector = malloc(sizeof(t_vector) * size_total)))
		fdf_err(2);
	i = 0;
	while (get_next_line(fd, &gnl + i))
	{
		printf("%s\n", gnl);
		j = 0;
		map_split = ft_strsplit(gnl, ' ');
		while (map_split[j])
		{
			vector[j].x = i;
			vector[j].y = j;
			vector[j].z = ft_atoi(map_split[j]);
			j++;
			vector++;
		}
		i++;
	}
	return (vector);
}

int			*create_tab(int *str, t_infowin *infos)
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
	ft_tabfree(split_matrix);
	return (result);
}

t_vector	*get_map(char *file)
{
	t_vector	*result;
	char 	*gnl;
	char 	**tmp;
	int		i;
	int		j;
	int		count;
	int 	fd;

	count = 0;
	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		fdf_err(2);
	while (get_next_line(fd, &gnl + i))
	{
		j = -1;
		tmp = ft_strsplit(gnl, ' ');
		while (tmp[++j])
			count++;
	}
	result = create_vector(count, fd);
	if (close(fd) == -1)
		fdf_err(2);
	return (result);
}



void		fdf_parser(char **tab, t_infowin *infos)
{
	int 	**tab;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(tab = (int **)malloc(sizeof(int *) * i)))
		ft_err(2);
	i = -1;
	infos->w = 0;
	while (str[++i])
		tab[i] = create_tab(str[i], infos);
	if (i == 0)
		fdf_err(1);
	infos->h = i;
	infos->tab = tab;
}
