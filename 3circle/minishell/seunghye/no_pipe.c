/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:58:49 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 16:36:26 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	check_minishell_file(char *cmd)
{
	if (!cmd || !*cmd)
		return ;
	if (!ft_strnstr(cmd, "minishell", ft_strlen(cmd)))
		return ;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static int	no_pipe_wait(char *cmd)
{
	extern t_pid	g_pid;
	int				status;

	signal(SIGINT, newline_sigint);
	check_minishell_file(cmd);
	waitpid(-1, &status, 0);
	signal(SIGINT, ori_handler);
	signal(SIGQUIT, SIG_IGN);
	g_pid.size = 0;
	g_pid.pid = 0;
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

int	no_pipe(t_info *info, t_list **env)
{
	extern t_pid	g_pid;
	int				builtin_id;
	pid_t			child;

	builtin_id = is_builtin(info->cmds[0]);
	if (builtin_id)
	{
		if (redi_handle(info->cmds[0]))
			return (1);
		return (execute_builtin(builtin_id, get_args(info->cmds[0]), env));
	}
	signal(SIGQUIT, sigquit_handle);
	g_pid.size = 1;
	child = fork();
	g_pid.pid = &child;
	if (*(g_pid.pid) == 0)
	{
		if (redi_handle(info->cmds[0]))
			exit(1);
		exit(execute_bin(get_args(info->cmds[0]), get_envp(*env)));
	}
	return (no_pipe_wait(get_cmd(info->cmds[0])));
}
