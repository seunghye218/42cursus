/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:31:50 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/29 13:01:30 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sem_clear(t_philo_config info)
{
	int		i;

	sem_unlink("fork");
	sem_unlink("room");
	sem_unlink("dead");
	i = 0;
	while (i < info.num_of_philo)
	{
		sem_unlink(info.sem_name[i]);
		i++;
	}
}

int	check_status(t_philo_config *info, int *status)
{
	int			i;
	static int	count;

	i = 0;
	if (WEXITSTATUS(*status) == 1)
	{
		while (i < info->num_of_philo)
			kill(info->pid[i++], SIGKILL);
		return (1);
	}
	else if (WEXITSTATUS(*status) == 0)
	{
		count++;
		if (count == info->num_of_philo)
			return (1);
	}
	return (0);
}

void	wait_child_end(t_philo_config *info)
{
	int	status;
	int	pid;

	while (1)
	{
		pid = waitpid(-1, &status, WNOHANG);
		if (pid == -1)
		{
			printf("waitpid error\n");
			exit(1);
		}
		else if (pid == 0)
			continue ;
		else
		{
			if (check_status(info, &status))
				return ;
		}
		usleep(1000);
	}
}

void	main_clear(t_philo_config *info)
{
	int	i;

	free(info->pid);
	sem_close(info->sem.fork);
	sem_close(info->sem.room);
	sem_close(info->sem.dead);
	sem_close(info->philo_sem);
	sem_clear(*info);
	i = 0;
	while (i < info->num_of_philo)
		free(info->sem_name[i++]);
	free(info->sem_name);
}

void	philo_clear(t_philo_config *info)
{
	int	i;

	free(info->pid);
	i = 0;
	while (i < info->num_of_philo)
		free(info->sem_name[i++]);
	free(info->sem_name);
	pthread_join(info->thr, 0);
}
