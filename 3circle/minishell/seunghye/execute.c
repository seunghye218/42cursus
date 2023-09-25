/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:39:19 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 16:25:17 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	my_clear(pid_t *pid, int (*pipe_fd)[2])
{
	free(pipe_fd);
	free(pid);
	return (1);
}

static int	ft_fork(int *i, t_info *info, pid_t *pid)
{
	while (*i < info->size)
	{
		pid[*i] = fork();
		if (pid[*i] == -1)
			return (ft_perror("fork error: "));
		else if (pid[*i] == 0)
			return (0);
		(*i)++;
	}
	return (0);
}

static int	if_child(int i, t_info *info, int (*pipe_fd)[2], pid_t *pid)
{
	if (i < info->size)
	{
		if (i != 0)
			dup2(pipe_fd[i - 1][0], 0);
		if (i + 1 != info->size)
			dup2(pipe_fd[i][1], 1);
		close_pipe(pipe_fd, info->size);
		if (redi_handle(info->cmds[i]))
			exit(my_clear(pid, pipe_fd));
		return (1);
	}
	return (0);
}

static void	execute_child(int i, t_info *info, t_list **env)
{
	signal(SIGQUIT, sigquit_handle);
	if (is_builtin(info->cmds[i]))
		exit(execute_builtin(\
		is_builtin(info->cmds[i]), get_args(info->cmds[i]), env));
	else
		exit(execute_bin(get_args(info->cmds[i]), get_envp(*env)));
}

unsigned char	execute(t_info *info, t_list **env)
{
	int				(*pipe_fd)[2];
	pid_t			*pid;
	int				i;
	int				status;
	extern t_pid	g_pid;

	g_pid.size = 0;
	if (info->size == 1)
		return (no_pipe(info, env));
	if (get_pipe_pid(info->size, &pipe_fd, &pid))
		return (1);
	g_pid.size = info->size;
	g_pid.pid = pid;
	i = 0;
	if (ft_fork(&i, info, pid))
		return (1);
	if (if_child(i, info, pipe_fd, pid))
		execute_child(i, info, env);
	close_pipe(pipe_fd, info->size);
	status = ft_wait(info->size, pid);
	my_clear(pid, pipe_fd);
	g_pid.size = 0;
	return (status);
}
