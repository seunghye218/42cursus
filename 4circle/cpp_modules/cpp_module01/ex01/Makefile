# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/09/30 14:00:32 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex01

SRC = Zombie.cpp main.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

CC := c++
CFLAGS := -std=c++98 -Wall -Wextra -Werror
CPPFLAGS := $(CFLAGS)

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

.PHONY : all clean fclean
