/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:03:53 by clfoltra          #+#    #+#             */
/*   Updated: 2018/12/05 20:10:17 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif_line(char **line)
{
	if (!**line)
		free(*line);
	return ((**line) ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static char	file[MAX_FD][BUFF_SIZE + 1];
	char		*buf;
	char		*pos;
	int			ret;

	buf = file[fd];
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strnew(0);
	while (TRUE)
	{
		if ((pos = ft_strchr(buf, 10)))
		{
			*line = ft_strjoinfree(*line, buf, pos - buf + 1, 1);
			ft_strncpy(buf, &buf[pos - buf + 1], BUFF_SIZE - (pos - buf));
			return (1);
		}
		*line = ft_strjoinfree(*line, buf, BUFF_SIZE, 1);
		ret = read(fd, file[fd], BUFF_SIZE);
		buf[ret] = '\0';
		if (!ret)
			return (ft_verif_line(line));
	}
}
