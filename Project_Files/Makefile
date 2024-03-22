NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = mlx

LXFLAGS = -framework OpenGL -framework AppKit

SRC = cub3d.c parse/parse.c parse/parse_map.c parse/parse_tools.c parse/parse_check.c gnl.c key.c screen.c screen_col.c tools.c parse/parse_helper.c libft/libft.a mlx/libmlx.a

OBJ = cub3d.o parse/parse.o parse/parse_map.o parse/parse_tools.o parse/parse_check.o gnl.o key.o screen.o screen_col.o parse/parse_helper.o tools.o

all: $(NAME)

$(NAME):
	make -C $(MLX)
	make -C libft
	$(CC) -o $(NAME) $(LXFLAGS) $(SRC)

clean:
	make clean -C libft
	make clean -C $(MLX)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
