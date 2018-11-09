NAME = libft.a
PATH_S = ./srcs/
PATH_I = ./includes/
SRCS = 	$(PATH_S)ft_memset.c \
		$(PATH_S)ft_bzero.c \
		$(PATH_S)ft_memset.c \
		$(PATH_S)ft_bzero.c \
		$(PATH_S)ft_memccpy.c \
		$(PATH_S)ft_memchr.c \
		$(PATH_S)ft_memcmp.c \
		$(PATH_S)ft_strlen.c \
		$(PATH_S)ft_strdup.c \
		$(PATH_S)ft_strcpy.c \
		$(PATH_S)ft_strncpy.c \
		$(PATH_S)ft_strcat.c \
		$(PATH_S)ft_strncat.c \
		$(PATH_S)ft_strlcat.c \
		$(PATH_S)ft_strchr.c \
		$(PATH_S)ft_strrchr.c \
		$(PATH_S)ft_strstr.c \
		$(PATH_S)ft_strnstr.c \
		$(PATH_S)ft_strcmp.c \
		$(PATH_S)ft_strncmp.c \
		$(PATH_S)ft_atoi.c \
		$(PATH_S)ft_isalpha.c \
		$(PATH_S)ft_isdigit.c \
		$(PATH_S)ft_isalnum.c \
		$(PATH_S)ft_isascii.c \
		$(PATH_S)ft_isprint.c \
		$(PATH_S)ft_toupper.c \
		$(PATH_S)ft_tolower.c \
		$(PATH_S)ft_memalloc.c \
		$(PATH_S)ft_memdel.c \
		$(PATH_S)ft_strnew.c \
		$(PATH_S)ft_strdel.c \
		$(PATH_S)ft_strclr.c \
		$(PATH_S)ft_striter.c \
		$(PATH_S)ft_striteri.c \
		$(PATH_S)ft_strmap.c \
		$(PATH_S)ft_strmapi.c \
		$(PATH_S)ft_strsub.c \
		$(PATH_S)ft_strjoin.c \
		$(PATH_S)ft_strtrim.c \
		$(PATH_S)ft_strsplit.c \
		$(PATH_S)ft_itoa.c \
		$(PATH_S)ft_putchar.c \
		$(PATH_S)ft_putstr.c \
		$(PATH_S)ft_putendl.c \
		$(PATH_S)ft_putnbr.c \
		$(PATH_S)ft_putchar_fd.c \
		$(PATH_S)ft_putstr_fd.c \
		$(PATH_S)ft_putendl_fd.c \
		$(PATH_S)ft_putnbr_fd.c 
OBJ = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJ)
	gcc $(FLAG) -c $(SRCS) -I $(PATH_I)
	ar rc $(NAME) $(OBJ)
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
