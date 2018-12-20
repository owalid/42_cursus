/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:40:53 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/20 20:49:44 by oel-ayad         ###   ########.fr       */
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
		j = 0;
		map_split = ft_strsplit(gnl, ' ');
		while (map_split[j])
		{
			vector->x = i;
			vector->y = j;
			vector->z = ft_atoi(map_split[j]);
			j++;
			vector++;
		}
		i++;
	}
	return (vector);
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
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		fdf_err(2);
	while (get_next_line(fd, &gnl + i))
	{
		j = 0;
		tmp = ft_strsplit(gnl, ' ');
		while (tmp[++i])
			count++;
		i++;
	}
	result = create_vector(count, fd);
	if (close(fd) != -1)
		fdf_err(2);
	return (result);
}


