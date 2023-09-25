/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:55:59 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/06 18:04:44 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	my_free(int (*pipe_fd)[2], pid_t **pid)
{
	free(pipe_fd);
	free(pid);
	ft_perror("get_pipe_pid error: ");
	return (1);
}

int	get_pipe_pid(int size, int (**pipe_fd)[2], pid_t **pid)
{
	int	i;

	*pipe_fd = malloc(sizeof(int *) * (size - 1));
	if (!*pipe_fd && my_free(0, 0))
		return (1);
	*pid = malloc(sizeof(pid_t) * size);
	if (!*pid && my_free(*pipe_fd, 0))
		return (1);
	i = 0;
	while (i + 1 < size)
	{
		if (pipe((*pipe_fd)[i]) && my_free(*pipe_fd, pid))
			return (1);
		i++;
	}
	return (0);
}

void	close_pipe(int (*pipe_fd)[2], int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}
