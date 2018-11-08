/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:03:47 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/08 16:05:52 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*memset(void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (i <= n)
	{
		s[i] = c;
	}
	return (s);
}
