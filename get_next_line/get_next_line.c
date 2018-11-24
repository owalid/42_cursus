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
void			ft_putstrf(char **str)
{
	int 	size = ft_strlen(*str) - 1;

	while (size--)
		printf("%c", *str[size]);
}

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
		//printf("\n[gnl in while: %s]", gnl);
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		ft_bzero((void*)gnl, ft_strlen(gnl));
		//gnl[nb_read] = '\0';
	}
	if (!nb_read && !**line)
		return (0);
	if (!separator)
	{
		//printf("\n\ngnl %s", gnl);
		ft_bzero((void *)gnl, ft_strlen(gnl));
		//gnl[nb_read] = '\0';
		*line = ft_strjoinfree(*line, gnl, ft_strlen(gnl));
		ft_strncpy(gnl, &gnl[BUFF_SIZE], ft_strlen(gnl));
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
		fd = 2;
	else if (argc == 2)
		fd = 2;
	else
		return (2);
	write(fd, "aaa\nbbb\nccc\n", 12);
	 close(fd);
	
		get_next_line(fd, &line);
		ft_putstrf(&line);
	//	printf("%d\n", strcmp(&line, "aaa"));
		get_next_line(fd, &line);
		//ft_putstrf(line);
	//	printf("%d\n", strcmp(line, "bbb"));
		get_next_line(fd, &line);
		//	ft_putstrf(line);
	//	printf("%d\n", strcmp(line, "ccc"));
		//ft_putendl(line);
		free(line);
	
	if (argc == 2)
		close(fd);
	return (1);
}
