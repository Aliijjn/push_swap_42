SRC = $(shell find ./src -iname "*.c")

LIBFTPATH = ./utils/libft/
LIBFT = $(LIBFTPATH)libft.a

PRINTFPATH = ./utils/ft_printf/
PRINTF = $(PRINTFPATH)ft_printf.a

NAME = push_swap

CFLAGS = -Werror -Wall -Wextra # -fsanitize=address

$(NAME) :
	make -C $(LIBFTPATH) all
	make -C $(PRINTFPATH) all
	cc $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTPATH) clean
	make -C $(PRINTFPATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPATH) fclean
	make -C $(PRINTFPATH) fclean

re: fclean all

.PHONY:
	all clean fclean re