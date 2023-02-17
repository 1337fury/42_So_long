NAME = so_long

NAME_B = so_long_bonus

CC =  cc

CFLAGS = -Wall -Wextra -Werror

INC = -I INCLUDES -I LIBFT/INCLUDES -I LIBFT/libft

MLX = -lmlx -framework OpenGL -framework AppKit

LIB_A = libftprintf.a

M_SRCS_PATH = SRCS/mandatory/
B_SRCS_PATH = SRCS/bonus/
S_SRCS_PATH = SRCS/shared/

M_SRCS_NAME = exit.c get_started.c map_checker.c map_checker_utils.c map_forming.c \
	move_player.c so_long.c start_playing.c check_images.c
B_SRCS_NAME = animation_bonus.c exit_bonus.c get_started_bonus.c map_checker_bonus.c \
	map_checker_bonus_utils.c map_forming_bonus.c map_forming_bonus_utils.c \
	move_enemies.c move_player_bonus.c so_long_bonus.c start_playing_bonus.c \
	check_images_bonus.c
S_SRCS_NAME = argument_checker.c error.c free_double.c map_dims.c

M_OBJS_NAME = $(M_SRCS_NAME:.c=.o)
B_OBJS_NAME = $(B_SRCS_NAME:.c=.o)
S_OBJS_NAME = $(S_SRCS_NAME:.c=.o)

M_OBJS = $(addprefix $(M_SRCS_PATH),$(M_OBJS_NAME))
B_OBJS = $(addprefix $(B_SRCS_PATH),$(B_OBJS_NAME))
S_OBJS = $(addprefix $(S_SRCS_PATH),$(S_OBJS_NAME))

MAN = $(M_OBJS) $(S_OBJS)
BONUS = $(B_OBJS) $(S_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $<

all : libcomp  $(NAME) 

bonus : libcomp $(NAME_B)

libcomp :
	@make -C LIBFT/
	@cp LIBFT/$(LIB_A) .

$(NAME) : $(MAN)
	mv $(M_OBJS_NAME) $(M_SRCS_PATH) 2> /dev/null || true
	mv $(S_OBJS_NAME) $(S_SRCS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(MLX) $(MAN) $(LIB_A) -o $@

$(NAME_B) : $(BONUS)
	mv $(B_OBJS_NAME) $(B_SRCS_PATH) 2> /dev/null || true
	mv $(S_OBJS_NAME) $(S_SRCS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(MLX) $(BONUS) $(LIB_A) -o $@

clean :
	@make clean -C ./LIBFT
	rm -f $(M_OBJS)
	rm -f $(B_OBJS)
	rm -f $(S_OBJS)

fclean : clean
	@make -C LIBFT/ fclean
	@rm -f $(LIB_A)
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)

re : fclean all

.PHONY: all clean fclean re libcomp