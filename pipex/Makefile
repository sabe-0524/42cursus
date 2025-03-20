# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 21:15:42 by abesouichir       #+#    #+#              #
#    Updated: 2025/03/09 16:37:56 by abesouichir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
NAME = pipex
SRCS = \
	main.c handler.c do_child.c
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