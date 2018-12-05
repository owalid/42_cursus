/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:03:21 by clfoltra          #+#    #+#             */
/*   Updated: 2018/11/26 10:38:46 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, size_t l, int opt)
{
	char		*ptr;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char*)ft_strnew(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strncat(ptr, s2, l);
	if (opt == 1)
		ft_strdel(&s1);
	if (opt == 2)
		ft_strdel(&s2);
	if (opt == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ptr);
}
