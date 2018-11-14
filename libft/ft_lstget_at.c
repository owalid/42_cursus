
#include "libft.h"

t_list		*ft_lstget_at(t_list *begin_list, size_t nb)
{
	t_list		*lst;
	size_t		i;

	i = 1;
	lst = begin_list;
	while (i < nb)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
		i++;
	}
	return (lst);
}
