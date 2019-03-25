void		sort_int_tab(int *tab, unsigned int size)
{
	int			i;
	int			a;

	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			a = i;
		}
		while (a)
		{
			if (tab[a - 1] > tab[a])
			{
				ft_swap(&tab[a], &tab[a - 1]);
				a--;
			}
			else
				a = 0;
		}
		i++;
	}
}

void		sort_int_tab(int *tab, unsigned int size)
{
	int 		i;
	int			a;

	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			a = i;
		}
		while (a)
		{
			if (tab[a - 1] > tab[a])
			{
				ft_swap(&tab[a], &tab[a-1]);
				a--;
			}
			else
				a = 0;
		}
		i++;
	}
}
