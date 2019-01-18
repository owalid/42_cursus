/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:45:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/18 16:04:17 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_err(int id)
{
	if (id == 1)
		ft_putendl(ERR_USAGE);
	exit(id);
}

void		frtl_exit(int id)
{
	if (id == 0)
		ft_putendl(EXIT);
	exit(id);
}
