NAME	= fdf

SRC		= fdf_parser.c \
			fdf_err.c \
			fdf_main.c \
			fdf_utils.c \
			fdf_windows_manager.c \
			fdf_display.c \
			fdf_usage.c \
			fdf_deal.c \
			fdf_line.c \
			fdf_clean.c \
			get_next_line.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

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

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
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
