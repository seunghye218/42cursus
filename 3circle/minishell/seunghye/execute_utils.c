/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:46:31 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 16:23:28 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	get_args_size(t_token *cmd)
{
	int	size;

	size = 0;
	while (cmd)
	{
		if (cmd->type == REDIR_TOKEN)
		{
			cmd = cmd->next->next;
			continue ;
		}
		size++;
		cmd = cmd->next;
	}
	return (size);
}

char	**get_args(t_token *cmd)
{
	char	**args;
	int		size;
	int		i;

	size = get_args_size(cmd);
	if (size == 0)
		return (0);
	args = malloc(sizeof(char *) * (size + 1));
	if (!args)
		return (0);
	args[size] = 0;
	i = 0;
	while (cmd)
	{
		if (cmd->type == REDIR_TOKEN)
		{
			cmd = cmd->next->next;
			continue ;
		}
		args[i++] = ft_strdup(cmd->content);
		cmd = cmd->next;
	}
	return (args);
}

int	ft_wait(int size, pid_t *pid)
{
	int		status;
	int		i;
	pid_t	wait_return;
	int		ret;

	i = 0;
	wait_return = 0;
	signal(SIGQUIT, sigquit_handle);
	signal(SIGINT, newline_sigint);
	while (i < size)
	{
		wait_return = waitpid(-1, &status, 0);
		if (wait_return == pid[size - 1])
		{
			if (WIFSIGNALED(status))
				ret = 128 + WTERMSIG(status);
			else
				ret = WEXITSTATUS(status);
		}
		i++;
	}
	signal(SIGINT, ori_handler);
	signal(SIGQUIT, SIG_IGN);
	return (ret);
}
