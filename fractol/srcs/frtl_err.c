/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:45:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 15:43:08 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/frtl.h"

void		frtl_err(int id)
{
	if (id == 1)
		ft_putendl_fd(ERR_USAGE, 2);
	if (id == 2)
		ft_putendl_fd(ERR_MLX, 2);
	exit(id);
}

void		frtl_exit(int id)
{
	if (id == 0)
		ft_putendl(EXIT);
	exit(id);
}
