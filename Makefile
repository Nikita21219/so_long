NAME =			so_long
HEADER =		so_long.h
HEADER_BONUS =	so_long_bonus.h
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS			=		mandatory/so_long.c mandatory/map/map_draw.c get_next_line/get_next_line_utils.c \
        		get_next_line/get_next_line.c mandatory/map/valid_map.c \
        		mandatory/free_utils.c mandatory/get_map.c mandatory/keypress_utils.c mandatory/pers_move.c \
        		mandatory/get_coord.c mandatory/keypress.c mandatory/map/unknown_key.c

SRCS_BONUS =	bonus/so_long_bonus.c bonus/map/map_draw_bonus.c get_next_line/get_next_line_utils.c \
        		get_next_line/get_next_line.c bonus/enemy/enemy_bonus.c \
        		bonus/animate/animate_bonus.c bonus/map/valid_map_bonus.c bonus/enemy/enemy_utils_bonus.c \
        		bonus/free_utils_bonus.c bonus/get_map_bonus.c bonus/keypress_utils_bonus.c bonus/pers_move_bonus.c \
        		bonus/get_coord_bonus.c bonus/keypress_bonus.c bonus/map/unknown_key_bonus.c

OBJ	=			$(SRCS:.c=.o)
OBJ_BONUS =		$(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	$(NAME)

$(NAME):	$(HEADER) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

bonus : $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all
.PHONY: all clean fclean re
