NAME = cub3D

COMPILE = gcc -Wall -Werror -Wextra

SOURCES = main.c filecontrol.c utils.c mapcontroller.c generalcontroller.c errorcontrol.c libft/libft.a get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c

all: $(NAME)

$(NAME):
	make -C libft/
	$(COMPILE) $(SOURCES) -o $(NAME)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
