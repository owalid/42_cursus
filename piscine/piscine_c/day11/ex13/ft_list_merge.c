/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 05:13:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 05:17:27 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	while (*begin_list1)
	{
		*begin_list1 = *begin_list1->next;
	}
	while (begin_list2)
	{
		*begin_list1->next = begin_list2;
		begin_list2 = begin_list2->next;
	}
}
