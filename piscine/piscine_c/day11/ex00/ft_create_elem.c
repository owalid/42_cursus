/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:58:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 03:51:18 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list		*result;

	result = malloc(sizeof(t_list));
	if (result == NULL)

	result->next = data;
	result->data = NULL;
	return (result);
}
