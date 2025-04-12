# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 20:08:34 by sabe              #+#    #+#              #
#    Updated: 2025/04/12 18:00:24 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = libft
GNL_PATH = get_next_line
MLX_PATH = minilibx-linux

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRC_FILES = src/main.c src/handle_map.c src/utils.c src/rotate.c src/move.c \
			src/draw.c src/color.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT = $(LIBFT_PATH)/libft.a
GNL = $(GNL_PATH)/libget_next_line.a
MLX = $(MLX_PATH)/libmlx.a

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX) $(GNL)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -L$(GNL_PATH) -lget_next_line

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(GNL):
	@$(MAKE) -C $(GNL_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C $(GNL_PATH) clean
	@rm -r $(OBJ_DIR)


fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(GNL_PATH) fclean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
