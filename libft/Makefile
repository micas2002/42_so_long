# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 13:27:06 by mibernar          #+#    #+#              #
#    Updated: 2023/04/04 17:38:44 by mibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -c -g

INCLUDES = -I $(HEADERS_DIRECTORY)

HEADERS_LIST = libft.h
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memset.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_putchar_fd.c ft_putnbr_fd.c \
	ft_calloc.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_memcmp.c ft_putstr_fd.c ft_memmove.c \
	ft_strjoin.c ft_putendl_fd.c ft_substr.c ft_strtrim.c ft_memcpy.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_split.c get_next_line.c get_next_line_utils.c ft_strcmp.c \
	ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_p.c \
	ft_printf_s.c ft_printf_u.c ft_printf_x_lower.c ft_printf_x_upper.c ft_unsigned_itoa.c

SOURCES_DIRECTORY = sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;92m
RED = \033[0;91m
CYAN = \033[0;96m
BLUE = \033[0;94m
RESET = \033[0m

# RULES

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(CYAN)$(NAME):$(RESET) $(GREEN)objects$(RESET) files were created"
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(NAME)$(RESET) was created"
	
$(OBJECTS_DIRECTORY):
	@echo "Compiling files"
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created"
	
$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@echo "Cleaning all object files:"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)$(OBJECTS_DIRECTORY)$(RESET) was deleted"
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)object files$(RESET) were cleaned"
	
fclean: clean
	@echo "Cleaning all object files and .a file:"
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME):$(RESET) $(RED)$(NAME)$(RESET) was cleaned"

re:
	@make fclean
	@make all

.PHONY:
	all clean fclean re