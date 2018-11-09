/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liste_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 00:03:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 03:43:23 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_liste_push_back(t_list **begin_list, void *data)
{
	int		i;
	t_list	*push;
	
	push = ft_create_elem(data);
	while (begin_list[i]->data == NULL)
		i++;
	begin_list[i]->next = push;
}
