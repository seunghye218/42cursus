# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 10:47:45 by seunghye          #+#    #+#              #
#    Updated: 2023/02/07 14:11:32 by seunghye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_vector_test std_vector_test \
		ft_map_test std_map_test \
		ft_stack_test std_stack_test \
		ft_set_test std_set_test \
		ft_main_test std_main_test

TEST_DIR := ./test_src/
VEC_SRC =  $(addprefix $(TEST_DIR),vector_test.cpp)
STACK_SRC = $(addprefix $(TEST_DIR),stack_test.cpp)
MAP_SRC = $(addprefix $(TEST_DIR),map_test.cpp)
SET_SRC = $(addprefix $(TEST_DIR),set_test.cpp)
MAIN_SRC = $(addprefix $(TEST_DIR),main.cpp)
# OBJ = $(SRC:.cpp=.o)

CC := c++
# DEBUG := -g3 -fsanitize=address
INCLUDE := -I./
FT := -DNAMESPACE=ft
STD := -DNAMESPACE=std
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 $(INCLUDE) $(DEBUG)

all : $(NAME)

$(NAME): $(VEC_SRC) $(MAP_SRC) $(STACK_SRC)

ft_vector_test :  $(VEC_SRC)
	$(CC) $(CXXFLAGS) $(FT) $(VEC_SRC) -o ft_vector_test
std_vector_test : $(VEC_SRC)
	$(CC) $(CXXFLAGS) $(STD) $(VEC_SRC) -o std_vector_test

ft_map_test : $(MAP_SRC)
	$(CC) $(CXXFLAGS) $(FT) $(MAP_SRC) -o ft_map_test
std_map_test : $(MAP_SRC)
	$(CC) $(CXXFLAGS) $(STD) $(MAP_SRC) -o std_map_test

ft_stack_test : $(STACK_SRC)
	$(CC) $(CXXFLAGS) $(FT) $(STACK_SRC) -o ft_stack_test
std_stack_test : $(STACK_SRC)
	$(CC) $(CXXFLAGS) $(STD) $(STACK_SRC) -o std_stack_test

ft_set_test : $(MAP_SRC)
	$(CC) $(CXXFLAGS) $(FT) $(MAP_SRC) -o ft_set_test
std_set_test : $(MAP_SRC)
	$(CC) $(CXXFLAGS) $(STD) $(MAP_SRC) -o std_set_test

ft_main_test : $(MAIN_SRC)
	$(CC) $(CXXFLAGS) $(FT) $(MAIN_SRC) -o ft_main_test
std_main_test : $(MAIN_SRC)
	$(CC) $(CXXFLAGS) $(STD) $(MAIN_SRC) -o std_main_test

clean :
	rm -f *.o log_ft log_std
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re
