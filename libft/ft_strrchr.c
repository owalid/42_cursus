/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:01:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/08 17:05:53 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_strrchr(const char *s, int c)
{
	int		i;
	int		find;

	find = -1;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			find = i;
	if (find != -1)
		return (&str[find]);
	return (NULL);
}
