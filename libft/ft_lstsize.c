
#include "libft.h"

int		ft_lst_size(t_list *begin_list)
{
	int		size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}
