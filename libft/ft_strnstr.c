/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:20:26 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/08 16:54:02 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(char *str, char *tofind, size_t n)
{
	int		i;
	int		j;

	i = 0;
	if (!str[i] && !tofind[i])
		return (s1[i]);
	while (str[i] && i <= n)
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return (str + i);
		i++;
	}
	return (0);
}
