NAME = fractol
SRC = *.c
LIBLINK = -L./libft -lft
MLXLINK = -L./minilibx -lmlx_Linux -lXext -lX11
MATHLINK = -lm
GFLAGS = -Wall -Wextra -Werror

$(NAME):
	make -C libft
	gcc $(GFLAGS) $(SRC) $(LIBLINK) $(MLXLINK) $(MATHLINK) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f libft/*.o
	/bin/rm -f minilibx/*.o

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f minilibx/libmlx.a
	/bin/rm -f $(NAME)

re: fclean all
