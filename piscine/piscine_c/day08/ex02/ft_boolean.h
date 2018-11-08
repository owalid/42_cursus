/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:28:44 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/14 23:03:11 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define TRUE			(1)
# define FALSE			(0)
# define EVEN_MSG		"I have an even number of arguments.\n"
# define ODD_MSG		"I have an odd number of arguments.\n"
# define SUCCESS		(0)
# define EVEN(nbr)		((nbr % 2) == 0 ? TRUE : FALSE)

typedef	int		t_bool;
#endif
