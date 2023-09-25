# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/09/28 17:19:06 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PhoneBook

SRC = main.cpp PhoneBook.cpp
OBJ = $(SRC:.c=.o)

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean
