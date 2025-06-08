# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 15:05:09 by sabe              #+#    #+#              #
#    Updated: 2025/06/08 16:15:39 by sabe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = tests

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
