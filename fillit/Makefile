# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 20:05:25 by clfoltra          #+#    #+#              #
#    Updated: 2018/12/05 20:10:35 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	utils.c \
  	  	fillit.c \
		get_next_line.c \
		solver.c \
		errors.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

INC = -I libft/includes -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		@printf "\n"
		@make -C libft/
		@printf "\n\n"
			@$(CC) $(CFLAGS) $(INC) -o $@ $^ 

clean:
		@make clean -C libft/
			@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
