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

NAME	=	cub3D

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g -Iincludes -MMD -MP

SRC_DIR =	src/mandatory
BNS_DIR	=	src/bonus

SOURCES	=	$(SRC_DIR)/cub3d.c \
			$(SRC_DIR)/parsing/check_extension.c \
			$(SRC_DIR)/parsing/handle_error.c \
			$(SRC_DIR)/parsing/initialise_structure.c \
			$(SRC_DIR)/parsing/free_functions.c \
			$(SRC_DIR)/parsing/read_header_of_map.c \
			$(SRC_DIR)/parsing/check_texture.c \
			$(SRC_DIR)/parsing/check_color.c \
			$(SRC_DIR)/parsing/utils.c \
			$(SRC_DIR)/clean/clean.c \
			$(SRC_DIR)/init/init_game.c \
			$(SRC_DIR)/event/event.c \
			$(SRC_DIR)/player_pos.c \
			$(SRC_DIR)/parsing/find_start_map.c \
			$(SRC_DIR)/parsing/allocate_map.c \
			$(SRC_DIR)/event/event_keyboard.c \
			$(SRC_DIR)/parsing/flood_fill.c \
			$(SRC_DIR)/parsing/find_player.c \
			$(SRC_DIR)/render/render_utils.c \
			$(SRC_DIR)/render/render.c \
			$(SRC_DIR)/init/init_ray.c \
			$(SRC_DIR)/dda/perform_dda.c \
			$(SRC_DIR)/calculate_wall_dist.c

BNS_SOURCES	= $(BNS_DIR)/cub3d_bonus.c \
			  $(BNS_DIR)/parsing/check_extension_bonus.c\
			  $(BNS_DIR)/parsing/handle_error_bonus.c \
			  $(BNS_DIR)/parsing/initialise_structure_bonus.c \
			  $(BNS_DIR)/parsing/free_functions_bonus.c \
			  $(BNS_DIR)/parsing/read_header_of_map_bonus.c \
			  $(BNS_DIR)/parsing/check_texture_bonus.c \
			  $(BNS_DIR)/parsing/check_color_bonus.c \
			  $(BNS_DIR)/parsing/utils_bonus.c \
			  $(BNS_DIR)/clean/clean_bonus.c \
			  $(BNS_DIR)/init/init_game_bonus.c \
			  $(BNS_DIR)/event/event_bonus.c \
			  $(BNS_DIR)/player_pos_bonus.c\
			  $(BNS_DIR)/parsing/find_start_map_bonus.c\
			  $(BNS_DIR)/parsing/allocate_map_bonus.c \
			  $(BNS_DIR)/event/event_keyboard_bonus.c \
			  $(BNS_DIR)/event/event_mouse_bonus.c \
			  $(BNS_DIR)/parsing/flood_fill_bonus.c \
			  $(BNS_DIR)/parsing/find_player_bonus.c \
			  $(BNS_DIR)/render/render_utils_bonus.c \
			  $(BNS_DIR)/render/render_bonus.c \
			  $(BNS_DIR)/init/init_ray_bonus.c \
			  $(BNS_DIR)/dda/perform_dda_bonus.c \
			  $(BNS_DIR)/calculate_wall_dist_bonus.c \
			  $(BNS_DIR)/render/render_minimap_bonus.c 

OBJ_DIR = obj/mandatory
OBJ_DIR_BONUS = obj/bonus

OBJECTS 		=	$(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS 	=	$(BNS_SOURCES:$(BNS_DIR)/%.c=$(OBJ_DIR_BONUS)/%.o)

MLX_LIB   = MacroLibX-master/libmlx.so

LIBFT	= libft/libft.a

LIBS 	= -lSDL2 -lm

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C MacroLibX-master -j

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

$(NAME): $(OBJECTS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT) $(LIBS) -o $(NAME)

bonus : $(OBJECTS_BONUS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(MLX_LIB) $(LIBFT) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: $(BNS_DIR)%.c | $(OBJ_DIR_BONUS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	$(MAKE) -C MacroLibX-master clean
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf obj
	$(MAKE) -C MacroLibX-master fclean
	$(MAKE) -C libft fclean

re: fclean all

-include $(OBJECTS:.o=.d) $(OBJECTS_BONUS:.o=.d)

.PHONY: all bonus clean fclean re

