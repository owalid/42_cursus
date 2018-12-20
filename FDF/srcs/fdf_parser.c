#include "../includes/fdf.h"

//taille du fichier = nombre de line 😎
int		get_size_file(char *file)
{
	int		fd;
	int		size;
	char 	*tmp;

	if (fd = open(file, O_RDONLY) == -1)
		fdf_err(2);
	while (get_next_line(fd, &tmp))
	{
		count++;
		free(tmp);
	}
	if (close(fd) != -1)
		fdf_err(2);
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
		fdf_err(2);
	while (get_next_line(fd, result + i))
		i++;
	if (close(fd) != -1)
		fdf_err(2);
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
	if (!(result = (int*)malloc(sizeof(int) * i)))
			fdf_err(2);
	i = -1;
	while (map_split[++i])
		result[i] = ft_atoi(map_split[i]);
	ft_strdel(map_split);
	return (result);
}

