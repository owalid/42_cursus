/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_list_remove_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 05:03:21 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/20 05:13:31 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *rm;
	t_list *cur;

	cur = *begin_list;
	while(*begin_list)
	{
		if (cmp(begin_list->next, data_ref) == 0)
		{
			rm = begin_list->next;
			cur = begin_list->next->next;
			free(rm);
		}
		cur = cur->next
	}
	*begin_list = cur;
	free(cur);
}
