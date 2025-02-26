# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 10:44:55 by sabe              #+#    #+#              #
#    Updated: 2024/05/07 12:04:42 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c print_x_up.c print_d.c print_p.c print_u.c print_c.c print_i.c print_s.c print_x.c libft/ft_itoa.c libft/ft_strlen.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ft_printf.h


$(NAME) :	$(OBJS)
	ar rc $@ $^

all : $(NAME)

%.o:%.c
	$(CC) -c  $(CFLAGS) $^ -o $@ $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re