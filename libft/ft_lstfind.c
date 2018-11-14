
#include "libft.h"

t_list		*ft_lstfind(t_list *begin_list, void *data)
{
	if (!begin_list)
		return (NULL);
	while (begin_list)
	{
		if (ft_memcmp(begin_list->content, data, begin_list->content_size) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
