# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#    Created: 2026/02/27 00:00:00 by sabe              #+#    #+#             #
#    Updated: 2026/02/27 00:00:00 by sabe             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = iter

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
