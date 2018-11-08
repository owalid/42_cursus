# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:02:06 by oel-ayad          #+#    #+#              #
#    Updated: 2018/11/08 14:12:16 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
all:
	@gcc $(FLAGS) -c $(SRC) 
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ) *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
