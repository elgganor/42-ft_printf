NAME=libftprintf.a

SRCS=ft_printf.c \
	./get_functions/get_flags.c \
	./get_functions/get_type.c \
	./get_functions/get_arg.c \
	./get_functions/get_char_numbers.c \
	./get_functions/get_space_numbers.c \
	./utils_functions/flags_utils.c \
	./utils_functions/flags_utils2.c \
	./utils_functions/check_types.c \
	./utils_functions/display_utils.c \
	./display_functions/ft_display.c \
	./display_functions/display_char.c \
	./display_functions/display_hex.c \
	./display_functions/display_integer.c \
	./display_functions/display_str.c

OBJ=${SRCS:.c=.o}

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
.o: .c
	@gcc $(FLAGS) -o $@ -c $<
clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJ)