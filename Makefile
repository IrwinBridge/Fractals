NAME = fractol
SRC = src/*.c src/fractals/*.c
HEADERS = -Iincludes
LIBLINK = -L./libft -lft
MLXLINK = -L./minilibx -lmlx_Linux -lXext -lX11
MATHLINK = -lm
PTHREADS = -lpthread
GFLAGS = -Wall -Wextra -Werror

$(NAME):
	make -C libft
	gcc $(GFLAGS) $(SRC) $(HEADERS) $(LIBLINK) $(MLXLINK) $(MATHLINK) $(PTHREADS) -Ofast -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f libft/*.o
	/bin/rm -f minilibx/*.o

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f minilibx/libmlx.a
	/bin/rm -f $(NAME)

re: fclean all
