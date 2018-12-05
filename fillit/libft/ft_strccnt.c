/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:21:39 by clfoltra          #+#    #+#             */
/*   Updated: 2018/12/05 11:56:42 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strccnt(char *s, char c)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			count++;
	return (count);
}
