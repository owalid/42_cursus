/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:56:34 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 04:08:53 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*result;
	unsigned int 	i;
	
	result = begin_list;
	i = 1;
	while (i != nbr)
	{
		if (!result)
			return (NULL);
		result = result->next;
		i++;
	}
	return (begin_list);
}
