# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/08/24 10:56:01 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

SRC = pipex.c
OBJ = $(SRC:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft.a -lreadline -I~/.brew/Cellar/readline/8.1.2/include -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean bonus
