/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:27:21 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/14 14:41:24 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

typedef struct			s_stock_par
{
	int			size_param;
	char		*str;
	char		*copy;
	char		**tab;
}						t_stock_par;

void					ft_putchar(char c);
#endif
