/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/26 16:02:06 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_verif_line(char **line)
{
	if (!**line)
		free(*line);
	return ((**line) ? 1 : 0);
}

char		*ft_strjoinfree(char *s1, char *s2, size_t len)
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

int			get_next_line(const int fd, char **line)
{
	static char		gnl[BUFF_SIZE];
	char			*separator;
	int				nb_read;
	int				position;

	if (fd < 0 || !line || read(fd, gnl, 0) < 0 ||
			BUFF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if ((separator = ft_strchr(gnl, '\n')))
		{
			position = (ft_strlen(gnl) - (ft_strlen(separator)));
			*line = ft_strjoinfree(*line, gnl, position);
			ft_strncpy(gnl, &gnl[position + 1], BUFF_SIZE - position);
			return (1);
		}
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		nb_read = read(fd, gnl, BUFF_SIZE);
		gnl[nb_read] = '\0';
		if (!nb_read)
			return (ft_verif_line(line));
	}
}
