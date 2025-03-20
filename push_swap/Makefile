# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 21:09:48 by abesouichir       #+#    #+#              #
#    Updated: 2025/03/20 18:00:59 by abesouichir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
NAME = push_swap
SRCS = \
  main.c handle_stack.c command_r.c command_rr.c command_s.c \
  command_p.c count_r.c count_r_util.c sort.c delete_r.c \
	sort_util.c handle_error.c check_stack.c
BSRCS = \
	checker_bonus.c checker_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
INCLUDES = -I. -I./libft -I./get_next_line
OBJS_COMMON = $(filter-out main.o, $(OBJS))

all : $(NAME)

libft/libft.a:
	$(MAKE) -C libft

get_next_line/get_next_line.a:
	$(MAKE) -C get_next_line

$(NAME) : $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

bonus: all get_next_line/get_next_line.a $(BOBJS)
	$(CC) $(CFLAGS) -o checker $(OBJS_COMMON) $(BOBJS) -L./get_next_line -lget_next_line $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJS)
	rm -f $(BOBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean

fclean : clean
	rm -f $(NAME)
	rm -f checker
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean
re : fclean all

.PHONY : all clean fclean re

