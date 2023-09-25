# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/10/25 16:56:08 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex01

SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

CC := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $@

.PHONY : all clean fclean re
