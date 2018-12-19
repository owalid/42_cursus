#include "../includes/fdf.h"

void	fdf_verif_ext(char *file)
{
	int i;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
		fdf_err(2);
}

int 	main(int ac char **av)
{
	if (ac > 1 && ac < 5)
	{
		fdf_verif_ext(av[1]);
		if (ac == 4)
			// modifier les valeurs par default de la fenetre
		else
		{
			info->width = 1280;
			info->heigth = 720;
		}
		map = get_map(av[1]);
		ft_parse(map, info);
		ft_strdel(map);
		ft_stctdel(info);
	}
	ft_err(0);
	return (0);
}
