/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:36:10 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/12 21:28:11 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	char		*tmp_s1;
	char		*tmp_s2;

	tmp_s1 = ft_strdup(s1);
	tmp_s2 = ft_strdup(s2);
	tmp_s1 = ft_strnlowcase(tmp_s1, n);
	tmp_s2 = ft_strlowcase(tmp_s2);
	return (ft_strcmp((const char*)tmp_s1, (const char *)tmp_s2));
}
