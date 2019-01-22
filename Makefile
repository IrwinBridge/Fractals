NAME = fractol
SRC = src/*.c src/fractals/*.c
HEADERS = -Iincludes
LIBLINK = -L./libft -lft
MLXLINK = -L./minilibx -lmlx -framework OpenGL -framework AppKit
MATHLINK = -lm
PTHREADS = -lpthread
GFLAGS = -Wall -Wextra -Werror -Ofast
OPENCL = -framework OpenCL

$(NAME):
	make -C libft
	make -C minilibx
	gcc $(GFLAGS) $(SRC) $(HEADERS) $(LIBLINK) $(MLXLINK) $(MATHLINK) $(PTHREADS) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f libft/*.o
	/bin/rm -f minilibx/*.o

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f minilibx/libmlx.a
	/bin/rm -f $(NAME)

re: fclean all
