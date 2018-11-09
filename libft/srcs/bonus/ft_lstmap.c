/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:44:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 16:52:25 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_sizelst(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}


t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;

	if ((result = (t_list)malloc(sizeof(t_list) * ft_sizelst(lst))) == NULL)
			return (NULL);
	while (lst)
	{
		result = f(lst);
		result = result->next;
		lst = lst->next;
	}
	return (result);
}
