/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:01:31 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/11/12 14:24:23 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap_tab(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void		ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (tab[i++])
		size++;
	i = 0;
	while (i < size - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap_tab(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
