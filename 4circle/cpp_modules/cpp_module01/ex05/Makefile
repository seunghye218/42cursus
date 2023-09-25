# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/10/03 17:47:03 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ex05

SRC = main.cpp Harl.cpp
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
