/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:57:43 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/09 16:38:03 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_pid	g_pid;

void	process(char *line, t_list **envs, t_info *info);
void	init_info(t_info *info, t_token **tokens);
int		only_space(char *line);

void	dup_fds(int *fd)
{
	fd[0] = dup(0);
	fd[1] = dup(1);
	if (fd[0] == -1 || fd[1] == -1)
	{
		strerror(errno);
		exit(-1);
	}
}

void	restore_tty_connection(int *fd)
{
	int	ret;

	ret = dup2(fd[0], 0);
	ret = dup2(fd[1], 1);
	if (ret == -1)
	{
		strerror(errno);
		exit(-1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	struct termios	term;
	t_list			*env_list;
	t_info			info;
	int				fd[2];

	if (argc != 1 || argv[0] == NULL)
		return (-1);
	dup_fds(fd);
	env_list = make_envs(envp);
	ft_memset(&info, 0, sizeof(t_info));
	set_environment(&term);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			process_signal_ctrl_d(g_pid.status);
		else if (*line == '\0' || only_space(line))
			free(line);
		else
			process(line, &env_list, &info);
		if (isatty(0) != 1 || isatty(1) != 1)
			restore_tty_connection(fd);
	}
	return (0);
}

int	only_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		++i;
	}
	return (1);
}

void	process(char *line, t_list **envs, t_info *info)
{
	t_token			**tokens;

	tokens = NULL;
	add_history(line);
	tokens = lexer(line, *envs, &(info->exit_status));
	if (tokens == NULL)
	{
		free(line);
		ft_putstr_fd("syntax error\n", 2);
		return ;
	}
	init_info(info, tokens);
	info->exit_status = process_heredoc(info);
	if (info->exit_status == 0)
		g_pid.status = execute(info, envs);
	info->exit_status = g_pid.status;
	unlink_heredoc_files();
	free(line);
	free_tokens(&tokens);
	free(info->cmds);
}
