/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:31:01 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/06 18:39:51 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_splited_str(char ***splited)
{
	int		i;

	i = 0;
	while ((*splited)[i])
		free((*splited)[i++]);
	free((*splited)[i]);
	free(*splited);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->size)
		free(info->cmds[i++]);
	free(info->cmds);
}

void	free_tokens(t_token ***tokens)
{
	int	i;

	i = 0;
	while ((*tokens)[i])
	{
		free((*tokens)[i]->content);
		free((*tokens)[i++]);
	}
	free(*tokens);
}

void	unlink_heredoc_files(void)
{
	DIR				*dir_ptr;
	struct dirent	*file;
	const char		*home = "/tmp/";
	const char		*prefix = "seungparseunghye";
	char			*tmp;

	dir_ptr = opendir(home);
	if (dir_ptr == NULL)
		ft_putstr_fd(strerror(errno), 2);
	else
	{
		while (1)
		{
			file = readdir(dir_ptr);
			if (file == NULL)
				break ;
			if (ft_strncmp(file->d_name, prefix, ft_strlen(prefix)) == 0)
			{
				tmp = ft_strjoin(home, file->d_name);
				unlink(tmp);
				free(tmp);
			}
		}
		closedir(dir_ptr);
	}
}
