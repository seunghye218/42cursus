/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:08:59 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/08 17:15:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	redi(t_token *cmd, int flag, mode_t mode)
{
	int	fd;

	if (mode)
		fd = open(cmd->next->content, flag, mode);
	else
		fd = open(cmd->next->content, flag);
	if (fd < 0)
	{
		if (*cmd->content == '<' && ft_strlen(cmd->content) == 1)
		{
			ft_putstr_fd("redirection error: ", 2);
			ft_putendl_fd(strerror(errno), 2);
		}
		return (1);
	}
	if (mode)
		dup2(fd, 1);
	else
		dup2(fd, 0);
	close(fd);
	return (0);
}

int	redi_handle(t_token *cmd)
{
	int		check_error;

	while (cmd)
	{
		if (cmd->type == REDIR_TOKEN)
		{
			if (*cmd->content == '>' && ft_strlen(cmd->content) == 1)
				check_error = redi(cmd, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			else if (!ft_strncmp(cmd->content, ">>", 2))
				check_error = redi(cmd, O_CREAT | O_WRONLY | O_APPEND, 0644);
			else
				check_error = redi(cmd, O_RDONLY, 0);
			if (check_error)
				return (1);
			cmd = cmd->next->next;
		}
		else
			cmd = cmd->next;
	}
	return (0);
}
