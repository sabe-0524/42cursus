# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 17:02:03 by sabe              #+#    #+#              #
#    Updated: 2025/06/26 20:20:19 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

LIBFT_PATH = libft

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -ggdb3
LDFLAGS = -lreadline

SRC_FILES = src/main.c src/utils.c \
			src/tokenizer/add_token.c src/tokenizer/handle_operator.c \
			src/tokenizer/handle_quote.c src/tokenizer/handle_space.c \
			src/tokenizer/init.c src/tokenizer/tokenizer.c \
			src/tokenizer/all_free.c src/tokenizer/in_quote.c \
			src/parser/parser.c src/parser/init.c src/parser/recur_pipe.c \
			src/parser/recur_redirect.c src/parser/parse_error.c \
			src/parser/free_ast.c src/parser/add_flag.c \
			src/expander/add_command.c src/expander/ex_dollar.c \
			src/expander/ex_quote.c src/expander/expand_word.c \
			src/expander/expander.c src/expander/init.c src/expander/change_content.c \
			src/expander/free_expander.c src/expander/expand_token.c \
			src/exec/ex_command.c src/exec/ex_pipe.c src/exec/exec.c \
			src/exec/first.c src/exec/init.c src/exec/recur_ex.c \
			src/exec/utils.c src/exec/ex_greater.c src/exec/ex_lesser.c \
			src/exec/ex_r_greater.c src/exec/ex_redirect.c src/exec/ex_r_lesser.c src/exec/all_free.c \
			src/exec/first_sub.c src/exec/recur_pipe.c src/exec/heredoc.c \
			src/exec/builtin/builtin.c src/exec/builtin/echo.c \
			src/exec/builtin/export.c src/exec/builtin/unset.c \
			src/exec/builtin/env.c src/exec/builtin/pwd.c src/exec/builtin/cd.c src/exec/builtin/exit.c \
			src/env/getenv.c src/env/make_env.c src/env/setenv.c src/env/unset.c \
			src/env/utils.c src/env/catenv.c src/env/all_free.c \
			src/sig/init.c src/sig/parent.c src/sig/child.c src/sig/heredoc.c
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
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
