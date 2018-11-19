/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/19 20:44:51 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
void	ft_strjoinfree(char *s1, char **line)
{
	if (s1 || line)
	{
	*line = s1;
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		*gnl[10240];
	char			buff[BUFF_SIZE + 1]; //buffer fic

	if (!line || BUFF_SIZE < 1 || read(fd, buff, BUFF_SIZE) < 0 || !(gnl[fd] = ft_strnew(0)))
		return (-1);
	// tant qu'on est pas sur un \n ni a la fin du fichier
	while (read(fd, buff, BUFF_SIZE) != 0)
	{
		gnl[fd] = buff;
		ft_strjoinfree(buff, line);
	}
	printf("%s", *line);
	return (1);
}

int		main(int argc, char **argv)
{
	int 	fd;
	char 	*line; //la line

	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
