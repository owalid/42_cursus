/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:25:46 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/09 16:51:49 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		ft_lstdel(&(*alst)->next, &del);
		free(*alst);
		del(*alst->content, *alst->content_size);
		*alst = NULL;
	}
}
