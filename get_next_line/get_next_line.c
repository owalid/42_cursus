/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/23 19:12:49 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
static char		*ft_strjoinfree(char *s1, char *s2, size_t len)
{
	char		*result;
	size_t		total_size;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char*)ft_strnew(sizeof(char) * total_size)))
		return (NULL);
	ft_strcpy(result, s1);
	ft_strncat(result, s2, len);
	ft_strdel(&s1);
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	static char 	gnl[BUFF_SIZE];
	char			*separator;
	int				nb_read;
	int				position;

	position = 0;
	if (fd < 0 || !line || read(fd, gnl, 0) < 0 || BUFF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);
	if ((position = ft_strlen(gnl)) > 0)
	{
		if ((separator = ft_strrchr(gnl, '\n')))
		{
			*line = ft_strjoinfree(*line, gnl, separator - gnl);
			ft_strncpy(gnl, &gnl[separator - gnl + 1],  BUFF_SIZE);
		}
		else
		{
			*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
			ft_bzero((void*)gnl, BUFF_SIZE);
		}
	}
	while ((nb_read = read(fd, gnl, BUFF_SIZE)) > 1)
	{
		//printf("\n[gnl in while: %s]", gnl);
		separator = ft_strrchr(gnl, '\n');
		if (separator)
		{
			*line = ft_strjoinfree(*line, gnl, separator - gnl);
			ft_strncpy(gnl, &gnl[separator - gnl + 1],  BUFF_SIZE);
			return (1);
		}
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		ft_bzero((void*)gnl, BUFF_SIZE);
	}
	if (!nb_read && !**line)
		return (0);
	return (1);
}


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (1);
}
