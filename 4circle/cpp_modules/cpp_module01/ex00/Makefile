# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/09/28 20:47:44 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex00

SRC = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -Wall -Wextra -Werror -std=c++98

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

.PHONY : all clean fclean
