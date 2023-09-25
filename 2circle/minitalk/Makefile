# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2022/04/27 20:41:26 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT := client
SERVER := server
NAME := $(CLIENT) $(SERVER)
BONUS := client_bonus server_bonus
SRC = ft_putnbr.c ft_atoi.c
OBJ = $(SRC:.c=.o)

LIBFT := libft.a
AR := ar
ARFLAGS := -rc

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BONUS)

clean :
	rm -f *.o
fclean : clean
	rm -f $(LIBFT) $(NAME) $(BONUS)
re : fclean all

$(NAME) : $(LIBFT) $(CLIENT:=.o) $(SERVER:=.o)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT:=.o) $<
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER:=.o) $<
$(BONUS) : $(LIBFT) $(CLIENT:=_bonus.o) $(SERVER:=_bonus.o)
	$(CC) $(CFLAGS) -o $(CLIENT:=_bonus) $(CLIENT:=_bonus.o) $<
	$(CC) $(CFLAGS) -o $(SERVER:=_bonus) $(SERVER:=_bonus.o) $<
$(LIBFT) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean bonus
