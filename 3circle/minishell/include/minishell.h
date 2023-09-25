/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:16:26 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 20:04:02 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <dirent.h>

# include "execute.h"

typedef struct s_chunk
{
	char			**splited;
	char			*env_name;
	char			*ret;
	char			*tmp;
	int				start;
	int				cnt;
	int				i;
	char			*str;
	t_list			*env;
	unsigned char	status;
}			t_chunk;

/* main.c */

/* make_envs.c */
t_list	*make_envs(char **envp);

/* signal_handler.c */
void	setting_signal(void);
void	process_signal_ctrl_d(int return_value);
void	heredoc_handler(int signal);
void	tmp_handler(int signal);

/* init_info.c */
void	init_info(t_info *info, t_token **tokens);

/* lexer.c */
t_token	**lexer(char *line, t_list *envs, unsigned char *exit_status);

/* lexer_util1.c */
char	**make_splited_str(char *line, int flag);
void	env_var_expand(char **splited, t_list *envs, unsigned char *s);
char	*remove_quotes(char *str);
int		include_single_quotes(char *str);
int		include_double_quotes(char *str);

/* lexer_util2.c */
int		have_only_one_quote(char *line);

/* lexer_util3.c */
void	add_tokens(t_token **token_list, char **splited);

/* lexer_util4.c */
char	*expand_env(char *str, t_list *env, unsigned char *status);

/* lexer_util5.c */
char	*get_env_value(char *s, t_list *env, unsigned char *exit_status);
/* lexer_util6.c */
int		get_start_pos(char *line, int start_index);
int		get_end_pos(char *line, int start_index);

/* lexer_util7.c */
int		get_end_pos_flag(char *line, int start_index);

/* string_util.c */
char	*get_strjoin_value(char **splited);

/* free.c */
void	free_splited_str(char ***splited);
void	free_info(t_info *info);
void	free_tokens(t_token ***tokens);
void	unlink_heredoc_files(void);

/* set_environment.c */
void	set_environment(struct termios *term);

/* syntax_check */
int		syntax_check(char **splited);

/* process_mixed_str */
int		str_mixed_quotes(char *s);
char	*process_mixed_str(char *s, t_list *envs, unsigned char *st);

/* process_heredoc */
t_token	*get_n_th_heredoc(t_info *info, int n);
int		process_heredoc(t_info *info);

/* process_heredoc_util.c */
void	replace_heredoc_end_to_filename(t_info *info, int n);

/* process_consequtive_string.c */
int		is_quotes_consequtive_string(char *line);
char	*process_consequtive_string(char *line, t_list *envs, unsigned char *s);

/* error.c */
void	*print_error_and_return(char *msg, int fd, void *ret);
int		print_error_and_return_int(char *msg, int fd, int ret);
void	print_error_and_exit(char *msg, int fd, int ret);

#endif
