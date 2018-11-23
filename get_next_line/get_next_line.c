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
	if (ft_strlen(gnl) > 0)
		*line = ft_strjoinfree(*line, gnl, ft_strlen(gnl));
	while ((nb_read = read(fd, gnl, BUFF_SIZE)) > 1 && !(separator = ft_strrchr(gnl, '\n')))
	{
		printf("gnl %s", gnl);
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		gnl[nb_read] = '\0';
	}
	if (!nb_read && !**line)
		return (0);
	if (!separator)
	{
		printf("gnl %s", gnl);
		gnl[nb_read] = '\0';
		*line = ft_strjoinfree(*line, gnl, ft_strlen(gnl));
		ft_strncpy(gnl, &gnl[ft_strlen(gnl)], ft_strlen(gnl));
		return (1);
	}
	position = (ft_strlen(gnl) - (ft_strlen(separator)));
	*line = ft_strjoinfree(*line, gnl, position);
	ft_strncpy(gnl, &gnl[position + 1],  BUFF_SIZE);
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
