# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 17:02:03 by sabe              #+#    #+#              #
#    Updated: 2025/04/27 17:18:34 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
LDFLAGS = -lreadline

SRC_FILES = src/main.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)


fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
