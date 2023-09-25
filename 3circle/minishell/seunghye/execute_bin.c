/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:48:32 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/08 16:14:54 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static char	**get_path(char **envp)
{
	char	**path;
	char	*tmp;
	int		i;

	if (!envp)
		return (0);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (0);
	path = ft_split(envp[i], ':');
	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = tmp;
		tmp = 0;
		i++;
	}
	return (path);
}

static char	*get_valid_path(char **args, char **path, struct stat *file_info)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!path || !args[0][0])
		return (0);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], args[0]);
		if (!tmp)
		{
			free_split(path);
			free_split(args);
			ft_putendl_fd("execute_bin(): ft_strjoin error", 2);
			return ((void *)1);
		}
		if (!stat(tmp, file_info))
			return (tmp);
		free(tmp);
		i++;
	}
	return (0);
}

static int	check_executable_file(char **args, struct stat file_info)
{
	mode_t	file_mode;

	file_mode = file_info.st_mode;
	if (S_ISDIR(file_mode) || file_mode != (file_mode | S_IXUSR))
	{
		ft_putstr_fd(args[0], 2);
		if (S_ISDIR(file_mode))
			ft_putstr_fd(": is a directory\n", 2);
		if (file_mode != (file_mode | S_IXUSR))
			ft_putstr_fd(": Permission denied\n", 2);
		free_split(args);
		return (1);
	}
	return (0);
}

int	if_tmp_null(char *tmp, char **args, char **envp)
{
	if (!tmp)
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_split(args);
		free_split(envp);
		return (1);
	}
	return (0);
}

int	execute_bin(char **args, char **envp)
{
	char		*tmp;
	char		**path;
	struct stat	file_info;

	if (check_args(args))
		return (bin_exception(args));
	path = get_path(envp);
	if (!stat(args[0], &file_info))
		execve(args[0], args, envp);
	else
	{
		tmp = get_valid_path(args, path, &file_info);
		if (if_tmp_null(tmp, args, envp))
			return (127);
		execve(tmp, args, envp);
		free(tmp);
	}
	free_split(envp);
	if (check_executable_file(args, file_info))
		return (126);
	free_split(args);
	return (ft_perror("execve error: "));
}
