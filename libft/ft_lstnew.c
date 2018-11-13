/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:36:07 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/13 15:47:25 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	if ((result = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	result->next = NULL;
	result->content = (void*)content;
	if (content != NULL)
		result->content_size = content_size;
	else
		result->content_size = 0;
	return (result);
}
