# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/04/20 13:24:02 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRC = $(NAME).c parsing.c check_dup.c \
		libft_utils.c ft_split.c ft_atol.c lst_utils.c \
		s_utils.c p_utils.c r_utils.c rr_utils.c \
		under_six_sort.c sort_utils.c greedy_sort.c
OBJ = $(SRC:.c=.o)

BONUS = checker
BONUS_SRC = my_checker.c parsing.c check_dup.c \
		libft_utils.c ft_split.c ft_atol.c lst_utils.c \
		s_utils.c p_utils.c r_utils.c rr_utils.c \
		under_six_sort.c sort_utils.c greedy_sort.c \
		get_next_line.c get_next_line_utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT := libft.a
BONUS_LIBFT := libft_bonus.a
AR := ar
ARFLAGS := -rc

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BONUS)

clean :
	rm -f *.o
fclean : clean
	rm -f $(LIBFT) $(BONUS_LIBFT) $(NAME) $(BONUS)
re : fclean all

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^
$(LIBFT) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

$(BONUS) : $(BONUS_OBJ) $(BONUS_LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $^
$(BONUS_LIBFT) : $(BONUS_OBJ)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean bonus
