# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/20 15:13:03 by xalves            #+#    #+#              #
#    Updated: 2026/06/24 16:58:07 by xalves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = cub3D

# COMPILER
CC = gcc-11
CFLAGS = -Wall -Wextra -Werror -g -fPIE

# PATHS
SRC_DIR = srcs
AUX_DIR = $(SRC_DIR)/aux
OBJ_DIR = obj

# MINILIBX
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# INCLUDES
INCLUDES = -Iincludes -I$(MLX_DIR)

# AUX LIBRARIES
GNL_LIB = $(AUX_DIR)/get_next_line/gnl.a
LIBFT_LIB = $(AUX_DIR)/libft/libft.a

# SOURCE FILES
SRC_FILES = main.c inputs.c init.c draw_funcs.c collisions.c raycast.c textures.c

# SOURCES
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# OBJECTS
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(GNL_LIB) $(LIBFT_LIB)
	@$(MAKE) CC=$(CC) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_LIB) $(LIBFT_LIB) \
		-o $(NAME) $(INCLUDES) $(MLX_FLAGS)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build GNL library
$(GNL_LIB):
	@$(MAKE) CC=$(CC) -C $(SRC_DIR)/aux/get_next_line

# Build Libft library
$(LIBFT_LIB):
	@$(MAKE) CC=$(CC) -C $(SRC_DIR)/aux/libft

# CLEAN
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) clean -C $(SRC_DIR)/aux/get_next_line
	@$(MAKE) clean -C $(SRC_DIR)/aux/libft

# FCLEAN
fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(SRC_DIR)/aux/get_next_line
	@$(MAKE) fclean -C $(SRC_DIR)/aux/libft

# REBUILD
re: fclean all

# PHONY
.PHONY: all clean fclean re