# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:50:03 by seunghye          #+#    #+#              #
#    Updated: 2022/04/12 19:49:34 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRCS := ft_printf.c ft_printf_utils.c
OBJS := $(SRCS:.c=.o)

LIBFT_DIR := ./libft/
LIBFT_LIB := libft.a
INCLUDE=-I./libft/

AR := ar
ARFLAGS := -rcs
CC := gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS = -Wall -Wextra -Werror

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f *.o
fclean : clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
re : fclean all

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_LIB) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(INCLUDE) -c $<

.PHONY : all clean fclean re bonus
