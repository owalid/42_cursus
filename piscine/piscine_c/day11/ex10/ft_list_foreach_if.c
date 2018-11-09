/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 04:52:27 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 04:59:23 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
		*data_ref, int (*cmp)(void *, void*))
{
	if (!begin_list)
		return (NULL);
	while (begin_list)
	{
		if (cmp(begin_list->data, data))
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
