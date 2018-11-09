/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 05:17:43 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 05:23:31 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*list;
	t_list	*list_next;

	list = *begin_list
	list_next = list->next;
	while (list)
	{
		if (cmp(list, list_next) > 0)
		{
			tmp = list;
			list = list_next;
			list_next = temp;
		}
		list = list->next;
		list_next = list->next;
	}
}
