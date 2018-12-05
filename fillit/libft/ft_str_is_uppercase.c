/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:41:00 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/14 12:42:54 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (ft_isupper(s[i]) == 0)
			return (0);
	return (1);
}
