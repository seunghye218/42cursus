# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:07:54 by seungpar          #+#    #+#              #
#    Updated: 2022/09/09 16:57:56 by seungpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -I$(shell brew --prefix readline)/include/ -Iinclude/
LIBS = -L$(shell brew --prefix readline)/lib/ -lreadline -Llibft -lft

SRCS = ./seungpar/main.c \
	   ./seungpar/lexer/lexer.c \
	   ./seungpar/lexer/lexer_util1.c \
	   ./seungpar/lexer/lexer_util2.c \
	   ./seungpar/lexer/lexer_util3.c \
	   ./seungpar/lexer/lexer_util4.c \
	   ./seungpar/lexer/lexer_util5.c \
	   ./seungpar/lexer/lexer_util6.c \
	   ./seungpar/lexer/lexer_util7.c \
	   ./seungpar/lexer/string_util.c \
	   ./seungpar/lexer/free.c \
	   ./seungpar/lexer/make_envs.c \
	   ./seungpar/lexer/signal_handler.c \
	   ./seungpar/lexer/init_info.c \
	   ./seungpar/lexer/syntax_check.c \
	   ./seungpar/lexer/process_mixed_str.c \
	   ./seungpar/lexer/process_heredoc.c \
	   ./seungpar/lexer/process_heredoc_util.c \
	   ./seungpar/lexer/error.c \
	   ./seungpar/lexer/set_environment.c \
	   ./seungpar/lexer/process_consequtive_string.c \
	   ./seunghye/env_lst_utils.c \
	   ./seunghye/execute.c \
	   ./seunghye/ft_cd.c \
	   ./seunghye/ft_echo.c \
	   ./seunghye/ft_exit.c \
	   ./seunghye/ft_export.c \
	   ./seunghye/ft_pwd.c \
	   ./seunghye/ft_unset.c \
	   ./seunghye/pipe_utils.c \
	   ./seunghye/redirection_utils.c \
	   ./seunghye/execute_bin.c \
	   ./seunghye/execute_utils.c \
	   ./seunghye/execute_builtin.c \
	   ./seunghye/libft_plus.c \
	   ./seunghye/ft_error.c \
	   ./seunghye/no_pipe.c \
	   ./seunghye/ft_env.c \
	   ./seunghye/execute_bin_utils.c \
	   ./seunghye/ft_signal.c \
	   
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) bonus -sC libft
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

.c.o :
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(MAKE) -sC libft clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -sC libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
