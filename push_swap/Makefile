# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 21:09:48 by abesouichir       #+#    #+#              #
#    Updated: 2025/03/03 20:24:24 by abesouichir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
NAME = push_swap
SRCS = \
  main.c handle_stack.c command_r.c command_rr.c command_s.c \
  command_p.c count_r.c count_r_util.c sort.c delete_r.c \
	sort_util.c handle_error.c check_stack.c
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

