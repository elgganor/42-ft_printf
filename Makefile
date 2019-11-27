NAME=libftprintf.a

SRCS=ft_printf.c \
	./get_functions/get_flags.c \
	./get_functions/get_type.c \
	./get_functions/get_arg.c \
	./get_functions/get_char_numbers.c \
	./utils_functions/flags_utils.c \
	./utils_functions/check_types.c

OBJ=${SRCS:.c=.o}

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $^
	ranlib $(NAME)
.o: .c
	gcc $(FLAGS) -o $@ -c $<
clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re