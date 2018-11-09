/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 00:14:28 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/17 14:13:35 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list(t_list *begin_list)
{
	while (begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}
