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

int			get_size(char **s)
{
	int 	i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		j = -1;
		while (s[i][++j])
			size++;
		i++;
	}
}


char		*get_fic(int fd, char **line)
{
	int		size;
	int 	i;
	char	*result;

	i = 0;
	size = 0;
	while (!read(fd, *line, BUFF_SIZE))
		size++;
	result = ft_strnew(size);
	while (!read(fd, *line, BUFF_SIZE))
		result[++i] = **line;
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	char	**gnl;
	int		i;
	int		j;
	char	*result;

	gnl = ft_strsplit(get_fic(fd, line), '\n');
	result = ft_strnew(get_size(gnl) / 2);
	while (gnl[i])
	{
		if (i % 2 == 0)
			result += gnl[i];
		i++;
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
