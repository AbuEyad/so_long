NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iheaders/

GAME = $(addprefix game/, check_assets.c  controls.c errors.c graphics.c map.c so_long.c utils.c)

GETNEXTLINE = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

FTPRINTF = $(addprefix ft_printf/, ft_itoa.c ft_printf.c ft_put_hex.c ft_put_ptr.c \
			ft_put_u_int.c ft_putchar_plus.c ft_putnbr_plus.c ft_putstr_plus.c)

SRCS = $(GAME) $(GETNEXTLINE) $(FTPRINTF)

OBJS = $(SRCS:.c=.o)

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX = minilibx/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRCS) $(LIBRARY) -o $(NAME)

clean:
	make clean -C $(MINILIBX)
	rm -rf $(OBJS)

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all

norm:
	norminette $(SRCS) headers/*.h

.PHONY:	all clean fclean re norm