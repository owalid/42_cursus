/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:03:37 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/10 16:38:48 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_gnl			*ft_lstgnlnew(char *str)
{
	t_gnl	*result;

	if ((result = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	result->str = ft_strdup(str);
	result->next = NULL;
	return (result);
}

void			ft_lstgnlpushback(t_gnl **beginlst, char *str)
{
	t_gnl	*push;

	push = ft_lstgnlnew(str);
	while ((*beginlst)->next)
		beginlst = &(*beginlst)->next;
	(*beginlst)->next = push;
}

int				ft_lstgnlsize(t_gnl *begin_list)
{
	int		size;
	t_gnl	*tmp;

	size = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

unsigned int	fdf_random_color(void)
{
	return (rand() * 0xFFFF00);
}

void			fdf_init_tab(t_infowin *infos)
{
	int			**ptr;
	int			i;

	i = -1;
	if (!(ptr = (int**)malloc(sizeof(int*) * (infos->w * infos->h))))
		fdf_err(2);
	while (i < infos->h * infos->w)
		if (!(ptr[++i] = (int*)malloc(sizeof(int) * 2)))
			fdf_err(2);
	infos->ptr = ptr;
}
