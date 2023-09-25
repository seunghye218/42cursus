/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:10:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 14:26:22 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "common.h"
# include <dirent.h>
# include <sys/stat.h>

enum	e_builtin
{
	echo_builtin = 1,
	cd_builtin,
	pwd_builtin,
	export_builtin,
	unset_builtin,
	exit_builtin,
	env_builtin
};

int				ft_cd(char **args, t_list **env);
int				ft_pwd(char **args, t_list **env);
int				ft_export(char **args, t_list **env);
int				ft_unset(char **args, t_list **env);
int				ft_echo(char **args, t_list **env);
int				ft_exit(char **args, t_list **env);
int				ft_env(char **args, t_list **env);

t_list			*get_val_cmp_pre(t_list *lst, char *value);
void			lstdel_node(t_list **lst, t_list *node);
t_list			*get_pre_node(t_list *lst, t_list *node);
char			**get_envp(t_list *env);

char			*ft_strndup(char *s, int n);
void			free_split(char **strs);

char			**get_args(t_token *cmd);
char			*get_cmd(t_token *cmd);

unsigned char	execute(t_info *info, t_list **env);
int				execute_builtin(int cmd_num, char **args, t_list **env);
int				execute_bin(char **args, char **envp);

int				no_pipe(t_info *info, t_list **env);

int				bin_exception(char **args);
int				check_args(char **args);
int				is_builtin(t_token *token);
int				ft_wait(int size, int *pid);
int				get_pipe_pid(int size, int (**pipe_fd)[2], pid_t **pid);
void			close_pipe(int (*pipe_fd)[2], int size);

int				redi_handle(t_token *cmd);
int				redi_builtin(t_token *cmd);
int				redi(t_token *cmd, int flag, mode_t mode);

int				ft_perror(char *s);
void			newline_sigint(int n);
void			ori_handler(int signum);
void			sigquit_handle(int n);

#endif