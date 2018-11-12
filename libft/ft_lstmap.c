/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:44:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/12 19:19:55 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_sizelst(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;

	if ((result = malloc(sizeof(t_list) * ft_sizelst(lst))) == NULL)
		return (NULL);
	while (lst)
	{
	//	result = ft_lstnew((*(f(lst)))->content, (*(f(lst))->content_size));
		result = f(lst);
		result = result->next;
		lst = lst->next;
	}

	return (result);
}
