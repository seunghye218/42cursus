# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/10/25 18:18:43 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex02

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CC := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $@

.PHONY : all clean fclean re
