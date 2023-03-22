# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 11:25:56 by mibernar          #+#    #+#              #
#    Updated: 2022/10/17 13:35:22 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c vars_utils.c map_utils.c player_utils.c open_imgs.c render.c \
		tilemap.c move_to.c check_path.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall
LIBFT_DIR = libft
PRINTF_DIR = printf

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
#	mac
#	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#	linux
	@$(CC) $(CFLAGS) $(OBJS) -L minilibx-linux/ -lmlx_Linux -lXext -lX11 -L$(PRINTF_DIR) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
