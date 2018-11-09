/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 04:59:40 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 18:18:06 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list)
		return(NULL);
	while (begin_list)
	{
		if (cmp(ft_list->data, data_ref) == 0)
			return (ft_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
