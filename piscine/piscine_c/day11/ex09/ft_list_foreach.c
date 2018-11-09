/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 04:49:37 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 04:52:04 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return (NULL);
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}
