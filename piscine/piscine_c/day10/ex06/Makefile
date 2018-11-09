# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 15:44:32 by oel-ayad          #+#    #+#              #
#    Updated: 2018/11/09 18:20:21 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
INCLUDE = ./includes/
PATH_SRC = ./src/
SRC = $(PATH_SRC)ft_atoi.c $(PATH_SRC)ft_operation.c $(PATH_SRC)ft_putnbr.c \
	  $(PATH_SRC)ft_do_op.c $(PATH_SRC)ft_strcmp.c $(PATH_SRC)ft_putchar.c \
	  $(PATH_SRC)ft_putstr.c
OBJ = $(SRC:.c=.o)
all: $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) -I $(INCLUDE)ft_op.h
%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean make
