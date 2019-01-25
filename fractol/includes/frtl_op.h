/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtl_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:47:38 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/01/25 18:54:01 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRTL_OP_H
# define FRTL_OP_H
# include "frtl.h"
static t_frtlop	g_frtlop[] =
{
	{1, MAND, &frtl_dspl_mand},
	{2, JU, &frtl_dspl_ju},
	{3, SHIP, &frtl_dspl_ship},
	{4, MY, &frtl_dspl_my},
	{0, "", &frtl_dspl_mand}
};

#endif
