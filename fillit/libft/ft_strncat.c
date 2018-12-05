/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:19:22 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/13 10:49:57 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = -1;
	j = ft_strlen(s1);
	while (s2[++i] && i < n)
		s1[i + j] = (char)s2[i];
	s1[i + j] = '\0';
	return (s1);
}
