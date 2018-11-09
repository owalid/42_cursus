/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:52:35 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/18 22:40:33 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_clear(t_list **begin_list)
{
	if (*begin_list)
	{
		ft_list_clear(&(*begin_list)->next);
		free(*begin_list);
		*begin_list = NULL;
	}
}
