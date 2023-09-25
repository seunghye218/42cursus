/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:02:23 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 16:37:50 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*get_cmd(t_token *cmd)
{
	while (cmd)
	{
		if (cmd->type != REDIR_TOKEN)
			return (cmd->content);
		cmd = cmd->next->next;
	}
	return (0);
}

int	is_builtin(t_token *token)
{
	char	*cmd;

	enum e_builtin;
	cmd = get_cmd(token);
	if (!cmd)
		return (0);
	if (!ft_strncmp(cmd, "echo", 5))
		return (echo_builtin);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (cd_builtin);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (pwd_builtin);
	else if (!ft_strncmp(cmd, "export", 7))
		return (export_builtin);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (unset_builtin);
	else if (!ft_strncmp(cmd, "exit", 5))
		return (exit_builtin);
	else if (!ft_strncmp(cmd, "env", 4))
		return (env_builtin);
	return (0);
}

int	execute_builtin(int cmd_num, char **args, t_list **env)
{
	static int	(*builtin[8])(char **, t_list **) = \
	{0, ft_echo, ft_cd, ft_pwd, ft_export, ft_unset, ft_exit, ft_env};
	int			exit_status;

	signal(SIGQUIT, SIG_IGN);
	if (!args)
		return (0);
	exit_status = builtin[cmd_num](args, env);
	if (exit_status == 1 && cmd_num != 6)
	{
		ft_putstr_fd(args[0], 2);
		ft_perror(": ");
	}
	else if (exit_status == 2)
		exit_status = 1;
	free_split(args);
	return (exit_status);
}
