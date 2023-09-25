# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:50:03 by seunghye          #+#    #+#              #
#    Updated: 2022/04/12 18:24:29 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS := ft_strlen.c ft_strlcpy.c ft_strdup.c ft_itoa.c \
		ft_ptoa.c ft_utoa_base.c
OBJS := $(SRCS:.c=.o)

AR := ar
ARFLAGS := -rcs
CC := gcc
CFLAGS := -Wall -Wextra -Werror

OBJ = $(OBJS)

all : $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all


$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean re bonus
