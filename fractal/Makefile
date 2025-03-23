# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 20:08:34 by sabe              #+#    #+#              #
#    Updated: 2025/03/23 20:26:47 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
# LDFLAGS = -L./libft -lft
NAME = fractal
SRCS = \
	main.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -I./minilibx-linux
LIBX_FLAGS = -lmlx -lXext -lX11

all : $(NAME)

# libft/libft.a:
# 	$(MAKE) -C libft

minilibx-linux/libmlx.a:
	$(MAKE) -C minilibx-linux

$(NAME) : $(OBJS) minilibx-linux/libmlx.a
	$(CC) $(CFLAGS) $(LIBX_FLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJS)
	# $(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME)
	# $(MAKE) -C libft fclean

re : fclean all

.PHONY : all clean fclean re
