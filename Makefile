# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 13:01:41 by jemonthi          #+#    #+#              #
#    Updated: 2025/12/05 13:04:23 by jemonthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g -Iincludes

SRC_DIR =	src

SOURCES	=	$(SRC_DIR)/cub3d.c \
			$(SRC_DIR)/check_extension.c \
			$(SRC_DIR)/handle_error.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/ft_split.c \
			$(SRC_DIR)/ft_substr.c \
			$(SRC_DIR)/initialise_structure.c \
			$(SRC_DIR)/ft_strcmp.c \
			$(SRC_DIR)/free_functions.c \
			$(SRC_DIR)/read_header_of_map.c 

OBJ_DIR = obj

OBJECTS =	$(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX_LIB   = MacroLibX-master/libmlx.so

LIBS        = -lSDL2

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C MacroLibX-master

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJECTS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C MacroLibX-master clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C MacroLibX-master fclean

re: fclean all

.PHONY: all clean fclean re

