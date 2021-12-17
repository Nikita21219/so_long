NAME = so_long
HEADER = so_long.h
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c map_draw.c
OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	$(NAME)

$(NAME):	$(HEADER) $(OBJ)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
