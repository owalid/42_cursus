# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 13:22:20 by oel-ayad          #+#    #+#              #
#    Updated: 2018/11/08 14:38:49 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = ./includes/
PATH_SRC = ./srcs/
SRC = $(PATH_SRC)ft_putchar.c $(PATH_SRC)ft_putstr.c $(PATH_SRC)ft_strcmp.c \
	 $(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_swap.c 
OBJ = ft_putchar.o ft_putstr.o ft_putstr.o ft_strcmp.o ft_swap.o ft_strlen.o 
all:
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDE)
	ar rc $(NAME) $(OBJ)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
