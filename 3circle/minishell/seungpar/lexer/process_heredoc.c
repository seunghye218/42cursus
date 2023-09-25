/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:29:33 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 17:22:57 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_heredoc_count(t_info *info)
{
	int		i;
	int		cnt;
	t_token	*cur;

	cnt = 0;
	i = -1;
	while (info->cmds[++i] != NULL)
	{
		cur = info->cmds[i];
		while (cur != NULL)
		{
			if (ft_strncmp(cur->content, "<<", 2) == 0)
				++cnt;
			cur = cur->next;
		}
	}
	return (cnt);
}

t_token	*get_n_th_heredoc(t_info *info, int n)
{
	int		i;
	int		cnt;
	t_token	*cur;

	cnt = 0;
	i = -1;
	while (info->cmds[++i] != NULL)
	{
		cur = info->cmds[i];
		while (cur != NULL)
		{
			if (ft_strncmp(cur->content, "<<", 2) == 0 && cnt == n)
				return (cur);
			else if (ft_strncmp(cur->content, "<<", 2) == 0)
				++cnt;
			cur = cur->next;
		}
	}
	return (NULL);
}

static void	read_file(const char *end, int i)
{
	int			fd;
	char		*filename;
	const char	*number = ft_itoa(i);
	char		*line;

	filename = ft_strjoin("/tmp/seungparseunghye", number);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error_and_exit(strerror(errno), 2, 1);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			exit(0);
		if (ft_strlen(line) == ft_strlen(end)
			&& ft_strncmp(line, end, ft_strlen(end)) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	free((void *)number);
	free(filename);
}

static void	process_heredoc_in_child(t_info *info, int i)
{
	t_token	*cur;
	char	*tmp;

	signal(SIGINT, heredoc_handler);
	cur = get_n_th_heredoc(info, i);
	cur = cur->next;
	tmp = cur->content;
	read_file(tmp, i);
	exit(0);
}

int	process_heredoc(t_info *info)
{
	int	i;
	int	pid;
	int	heredoc_cnt;

	pid = 0;
	signal(SIGINT, tmp_handler);
	i = -1;
	heredoc_cnt = get_heredoc_count(info);
	while (++i < heredoc_cnt)
	{
		pid = fork();
		if (pid == -1)
			return (print_error_and_return_int(strerror(errno), 2, -1));
		else if (pid == 0)
			process_heredoc_in_child(info, i);
		else
			wait(&pid);
		if (WEXITSTATUS(pid) == 1)
			break ;
		replace_heredoc_end_to_filename(info, i);
	}
	set_environment(NULL);
	return (pid);
}
