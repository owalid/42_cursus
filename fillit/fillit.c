/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:42 by clfoltra          #+#    #+#             */
/*   Updated: 2018/12/05 20:19:10 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_table(char **tab)
{
	char	**tmp_all;
	char	*tmp;
	int		i;

	i = 0;
	tmp_all = tab;
	tmp = *tab;
	while (tmp)
	{
		ft_strdel(&tmp);
		tmp = *++tab;
		i++;
	}
	ft_memdel((void *)&tmp_all);
}

static void		free_lst(t_tetri *lst)
{
	t_tetri *tmp;

	while (lst)
	{
		tmp = lst;
		free_table(lst->tetri);
		lst = lst->next;
		ft_memdel((void *)&tmp);
	}
}

static void		ft_putresult(char **tab)
{
	int i;

	i = -1;
	if (tab)
		while (tab[++i])
			ft_putendl(tab[i]);
}

static char		**ft_create_table(char **tab, int size)
{
	char	**result;
	int		i;
	int		j;

	if (tab)
		free_table(tab);
	if (!(result = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		result[i] = ft_strnew(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			result[i][j] = '.';
		result[i][j] = '\0';
	}
	result[size] = NULL;
	return (result);
}

int		main(int argc, char **argv)
{
	t_tetri		*res;
	char		**tb;
	int			fd;
	int			size;

	size = 2;
	tb = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_exit(ERROR, 1);
		res = read_file(fd);
		if (!errors(res) || !(tb = ft_create_table(tb, size)))
			ft_exit(ERROR, 1);
		while (!solv_fillit(res, tb))
			tb = ft_create_table(tb, size++);
		ft_putresult(tb);
		free_table(tb);
		free_lst(res);
		if (close(fd) == -1)
			ft_exit(ERROR, 1);
	}
	else
		ft_exit(FILEERR, 1);
	return (0);
}
