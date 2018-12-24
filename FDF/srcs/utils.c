/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:19:47 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/12/24 16:37:14 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_gnl		*ft_lstgnlnew(char *str)
{
	t_gnl	*result;

	if ((result = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	result->str = str;
	result->next = NULL;
	return (result);
}

void		ft_lstgnlpushback(t_gnl **beginlst, char *str)
{
	t_gnl	*push;

	push = ft_lstgnlnew(str);
	while ((*beginlst)->next)
		beginlst = &(*beginlst)->next;
	(*beginlst)->next = push;
}

int		ft_lstgnlsize(t_gnl *begin_list)
{
	int		size;
	t_gnl	*tmp;
	size = 0;
	
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
