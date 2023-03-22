# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 13:33:51 by mibernar          #+#    #+#              #
#    Updated: 2022/09/23 12:24:14 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_p.c \
		ft_printf_s.c ft_printf_u.c ft_printf_x_lower.c ft_printf_x_upper.c \
		ft_unsigned_itoa.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall
LIBFT_DIR = libft

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS) $(INC)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all
