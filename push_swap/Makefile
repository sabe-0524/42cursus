# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 21:09:48 by abesouichir       #+#    #+#              #
#    Updated: 2025/02/26 19:04:31 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
NAME = push_swap
SRCS = main.c handle_stack.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I. -I./libft

all : $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(NAME) : $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY : all clean fclean re

