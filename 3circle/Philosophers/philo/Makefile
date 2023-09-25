# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/07/28 19:36:01 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRC = philo.c ft_atoi.c time_utils.c init_utils.c check_arg.c thread_utils.c \
		philo_utils.c monitoring.c
OBJ = $(SRC:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

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

.PHONY : all clean fclean bonus
