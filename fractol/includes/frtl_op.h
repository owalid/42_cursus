/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:47:38 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/30 15:41:56 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRTL_OP_H
# define FRTL_OP_H

# include "frtl.h"

static t_frtlop	g_frtlop[] =
{
	{1, MAND, &frtl_dspl_mand, &frtl_init_mand},
	{2, JU, &frtl_dspl_ju, &frtl_init_ju},
	{3, SHIP, &frtl_dspl_ship, &frtl_init_ship},
	{4, MY, &frtl_dspl_my, &frtl_init_my},
	{5, NEW, &frtl_dspl_new, &frtl_init_newton},
	{0, "", &frtl_dspl_mand, &frtl_init_mand}
};

#endif
