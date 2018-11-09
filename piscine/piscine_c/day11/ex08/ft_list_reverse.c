/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:19:47 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 04:49:17 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*result;
	t_list	*tmp;
	
	if (*begin_list || *begin_list->next)
		return (NULL);


}
