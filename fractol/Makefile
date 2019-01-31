# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 14:34:20 by oel-ayad          #+#    #+#              #
#    Updated: 2019/01/30 15:42:32 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= frtl_main.c \
			frtl_err.c \
			frtl_windows.c \
			frtl_deal.c \
			frtl_deal_mouse.c \
			frtl_mand.c \
			frtl_ju.c \
			frtl_my.c \
			frtl_newton.c \
			frtl_ship.c \
			frtl_utils.c \
			frtl_init.c \
			frtl_usage.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 

MLX		= ./mlx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./mlx
MLX_LNK	= -L ./mlx -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -o $@ -c $< -I $(INCDIR)

$(NAME): $(OBJ) 
	make -C $(MLX)
	make -C $(FT) 
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all obj fclean clean re
