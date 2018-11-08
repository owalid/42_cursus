/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 23:37:13 by oel-ayad          #+#    #+#             */
/*   Updated: 2018/08/18 16:48:01 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>

# define ERR_MOD	"Stop : modulo by zero\n"
# define ERR_DIV	"Stop : division by zero\n"
# define ERR_ARGC	"error : only [ + - * / % ] are accepted.\n"

int					ft_strcmp(char *s1, char *s2);
void				ft_putnbr(int nb);
int					ft_atoi(char *str);
void				ft_putchar(char c);
int					ft_add(int nb1, int nb2);
int					ft_div(int nb1, int nb2);
int					ft_sub(int nb1, int nb2);
int					ft_mul(int nb1, int nb2);
int					ft_mod(int nb1, int nb2);
int					ft_usage(int nb1, int nb2);
void				ft_putstr(char *str);

typedef struct		s_opp
{
	char		*op;
	int			(*put_f)(int, int);
}					t_opp;

#endif
