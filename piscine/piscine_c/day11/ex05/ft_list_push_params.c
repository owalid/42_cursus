/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 00:18:50 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/17 14:15:01 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list *result;
	int		i;

	i = ac;
	while (i != 0)
	{
		result->next = ft_create_elm(av[i]);
		result = result->next;
		i--;
	}
	return (result);
}
