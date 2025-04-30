# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 17:02:03 by sabe              #+#    #+#              #
#    Updated: 2025/04/30 15:30:35 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

LIBFT_PATH = libft

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
LDFLAGS = -lreadline

SRC_FILES = src/main.c \
			src/tokenizer/add_token.c src/tokenizer/handle_operator.c src/tokenizer/handle_quote.c src/tokenizer/handle_space.c src/tokenizer/init.c src/tokenizer/tokenizer.c src/tokenizer/all_free.c src/tokenizer/in_quote.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT = $(LIBFT_PATH)/libft.a

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@$(CC) -o $@ $^ -L$(LIBFT_PATH) -lft $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) fclean


fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
