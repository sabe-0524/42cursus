# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 20:08:34 by sabe              #+#    #+#              #
#    Updated: 2025/07/08 12:21:57 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRC_FILES = src/main.c src/init.c src/philo.c src/utils.c src/ft_atoi.c src/finish.c src/handle_end.c src/philo_utils.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

NAME = philo

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean:
	$(RM) -rf $(OBJ_DIR)


fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
