NAME = cub3D

COMPILE = gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit

SOURCES = main.c filecontrol.c utils.c mapcontroller.c generalcontroller.c errorcontrol.c libft/libft.a get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c preparemlx.c mlx/libmlx.a ifpressescandgeneral.c ifpresswasd.c ifpresskeys.c calculatepixel.c

all: $(NAME)

$(NAME):
	make -C libft/
	make -C mlx/
	$(COMPILE) $(SOURCES) -o $(NAME)

clean:
	make clean -C libft/
	make clean -C mlx/

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
