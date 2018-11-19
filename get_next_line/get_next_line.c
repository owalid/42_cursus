/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/17 20:32:11 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	static char		*gnl[];
	char			buff[BUFF_SIZE + 1];

	if (!line || BUFF_SIZE < 1 || read(fd, buff, BUFF_SIZE) < 0 || !gnl)
		return (-1);
	while (!ft_strrchr(gnl[fd], '\n') && read(fd, buff, BUFF_SIZE))
	{
		//tant qu'on est pas sur un \n ni a la fin du fichier
		//.......
	}
}

int		main(int argc, char **argv)
{
	int 	fd;
	char 	**line;

	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	close(fd);
	return (0);
}
