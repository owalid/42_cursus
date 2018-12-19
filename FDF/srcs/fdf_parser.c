#include "../includes/fdf.h"

int		get_size_file(char *file)
{
	int		fd;
	int		size;
	char 	*tmp;

	if (fd = open(file, O_RDONLY) == -1)
		return (-1);
	while (get_next_line(fd, &tmp))
	{
		count++;
		free(tmp);
	}
	if (clos(fd) != -1)
		return (-1);
	return (count);
}

char	**get_map(char *file)
{
	char 	**result;
	int		i;
	int 	fd;

	i = 0;
	if ((fd = open(file, O_RDONLY) == -1) || 
			(result = (char**)malloc(sizeof(char*) * get_size_file(file + 1))))
		return (NULL);
	while (get_next_line(fd, result + i))
		i++;
	if (close(fd) != -1)
		return (-1);
	return (result);
}

int		*create_tab(char *map)
{
	int 	i;
	int		*result;
	char	**map_split;

	i = 0;
	map_split = ft_strsplit(map, ' ');
	while (map_split[i])
		i++;
	if (!(result = (int*)malloc(sizeof(int) * i)i))
			return (NULL);
	i = -1;
	while (map_split[++i])
		result[i] = ft_atoi(map_split[i]);
	ft_strdel(map_split);
	return (result);
}
