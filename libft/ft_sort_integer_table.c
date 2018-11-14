
#include "libft.h"

void		ft_sort_integer_table(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 1;
		}
		else
			i++;
	}
}
