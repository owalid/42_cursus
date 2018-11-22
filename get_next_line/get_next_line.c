/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/22 19:56:02 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

char		*ft_replace(char *str)
{
	int		i;
	int		size;

	size = ft_strlen(str);
	i = 0;
	if (size != 0)
	{
		while (size != 1)
		{
			str[i] = str[i + 1];
			i++;
			size--;
		}
	}
	return (str);
}
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
	int				position;

	if (fd < 0 || !line || read(fd, gnl, 0) < 0 || BUFF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);

	//printf("\x1B[32m[gnl: %s]\n", gnl);
	if (ft_strlen(gnl) > 1)
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
	while ((nb_read = read(fd, gnl, BUFF_SIZE) > 0) && !(separator = ft_strrchr(gnl, '\n')))
	{
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		//	printf("\x1B[34m[line: %s]", *line);
	}
	//	printf("\x1B[34m[line: %s]", *line);
	if (!separator)
	{
		//ft_strncpy(gnl, &gnl[ft_strlen(gnl)], ft_strlen(gnl));
		*line = ft_strjoinfree(*line, gnl, ft_strlen(gnl));
		return (0);
	}
	position = (ft_strlen(gnl) - (ft_strlen(separator)));
	*line = ft_strjoinfree(*line, gnl, position);
	//printf("\x1B[32m[position: %d]\n", position);
	//printf("\x1B[34m[line: %s]", *line);
	ft_strncpy(gnl, &gnl[position + 1], ft_strlen(gnl));
	//printf("\x1B[34m[line: %s]", *line);
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
	if (get_next_line(fd, &line) == 0)
	{
		ft_putendl(line);
		free(line);
		return (1);
	}
	if (argc == 2)
		close(fd);
	return (1);
}
