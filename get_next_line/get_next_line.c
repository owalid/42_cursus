/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/20 15:00:22 by oel-ayad         ###   ########.fr       */
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
	total_size = ft_strlen(s1) + len;
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

	if (fd < 0 || !line || read(fd, gnl, 0) < 0 || BUFF_SIZE < 1 || !(*line = ft_strdup("")))
		return (-1);
	while ((nb_read = read(fd, gnl, BUFF_SIZE) > 0) && !(separator = ft_strrchr(gnl, '\n')))
	{
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		gnl[nb_read] = '\0';
	}
	if (!separator)
		return (0);
	*line = ft_strjoinfree(*line, gnl, separator - gnl);
	ft_strncpy(gnl, &gnl[separator - gnl + 1], BUFF_SIZE - (separator - gnl));
	gnl[nb_read] = '\0';
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
