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

CFLAGS	=	-Wall -Wextra -Werror

SOURCES	=	cub3d.c

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

MLX_LIB   = MacroLibX-master/libmlx.so

LIBS        = -lSDL2

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C MacroLibX-master

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJECTS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C MacroLibX-master clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C MacroLibX-master fclean

re: fclean all

.PHONY: all clean fclean re

