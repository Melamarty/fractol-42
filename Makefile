SRCS = fractol.c utils.c mlx_hooks.c draw.c mandelbrot.c check_args.c \
		cubic_mandelbrot_bonus.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	cc $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $@

%.o: %.c fractol.h
	cc $(CFLAGS) -Imlx -c $< -o $@
bonus : $(NAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
