/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:13:36 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/12 19:18:51 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_printable(const char *str)
{
	int 		i;

	i = -1;
	while (str[++i])
		if (!(ft_isprint(str[i])))
			return (0);
	return (1);
}
