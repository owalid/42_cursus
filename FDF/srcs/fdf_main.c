#include "../includes/fdf.h"

void	fdf_verif_ext(char *file)
{
	int i;

	i = ft_strlen(file) - 4;
	if (i <= 0 || ft_strcmp(file + i, ".fdf"))
		fdf_err(2);
}
void	fdf_setwin(t_infos *infos, char *x, char *y)
{
	infos->width = ft_atoi(x);
	infos->height = ft_atoi(y);
}

int 	main(int ac char **av)
{
	char		**map;
	t_infos		infos[1];

	if (ac > 1 && ac < 5)
	{
		fdf_verif_ext(av[1]);
		if (ac == 4)
			fdf_setwin(infos,  av[2], av[3]);
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
	ft_err(1);
	return (0);
}
