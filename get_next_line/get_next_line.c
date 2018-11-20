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

static char 	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2 || !(result = ft_strnew(ft_strlen(s1) + size)))
		return (NULL);
	while (s1[++j])
		result[++i] = s1[j];
	j = -1;
	while (s2[++j] && --size > 0)
		result[++i] = s2[j];
	result[i] = '\0';
	return (result);
}


static int		ft_strlenat(char *str, char c)
{
	int 	i;
	int 	to_find;

	to_find = -1;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			to_find = i;
	return (to_find);
}

int		get_next_line(const int fd, char **line)
{
	static char		*gnl[10240];
	char			buff[BUFF_SIZE + 1]; //buffer fic
	int				fd_read;

	if (!line || fd <= -1 || BUFF_SIZE < 1 || read(fd, buff, BUFF_SIZE) < 0 || !(gnl[fd] = ft_strnew(0)))
		return (-1);
	// tant qu'on est pas sur un \n ni a la fin du fichier
	while (!(ft_strrchr(buff, '\n')) && (fd_read = read(fd, buff, BUFF_SIZE) > 0))
	{
		printf("%s", buff);
		buff[fd_read] = '\0';
		gnl[fd_read] = ft_strnjoin(gnl[fd_read], buff, OPEN_MAX);
	}
	//printf("");
	printf("\n%d", ft_strlenat(gnl[fd], '\n'));
	//*line = ft_strsub(gnl[fd], 0, ft_strlenat(gnl[fd], '\n'));
	if (line)
		return (1);
	return (0);
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
