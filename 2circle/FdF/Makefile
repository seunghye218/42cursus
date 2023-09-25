# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2023/09/25 11:24:07 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

DIR := ./mandatory/
SRC_NAME = fdf.c \
			libft_utils.c ft_atoi.c ft_split.c ft_htoi.c \
			parsing.c error_utils.c line_algorithm.c rotation_utils.c \
			key_hook_utils.c mouse_hook_utils.c map_utils.c draw_utils.c
SRC = $(addprefix $(DIR),$(SRC_NAME))
OBJ = $(SRC:.c=.o)

BONUS := $(NAME:%=%_bonus)
BONUS_DIR := ./bonus/
BONUS_SRC = $(SRC_NAME:%.c=$(BONUS_DIR)%_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

MLX_LIB := libmlx.dylib
MLX_FLAG := -Lmlx -lmlx -framework OpenGL -framework AppKit

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BONUS)

clean :
	rm -f *.o ./mlx/*.o ./mandatory/*.o ./bonus/*.o
fclean : clean
	rm -f $(NAME) $(BONUS) $(MLX_LIB)
re : fclean all


$(NAME): $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAG) -o $@

$(MLX_LIB) :
	make -C ./mlx

$(BONUS) : $(MLX_LIB) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAG) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

.PHONY : all clean fclean bonus
