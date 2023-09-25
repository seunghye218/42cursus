/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:07:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/28 23:45:33 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pid_t	create_philo(t_philo_config *info)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < info->num_of_philo)
	{
		info->philo_id = i;
		pid = fork();
		if (pid == -1)
		{
			printf("fork error\n");
			exit(1);
		}
		else if (pid == 0)
			return (0);
		info->pid[i] = pid;
		i++;
	}
	return (pid);
}

static int	sleeping_and_thinking(int philo_id, t_philo_config *info)
{
	if (sem_print(philo_id, "is sleeping", info))
		return (1);
	ft_msleep(info->time_to_sleep + get_time_ms());
	if (sem_print(philo_id, "is thinking", info))
		return (1);
	return (0);
}

static int	check_eat_times(int philo_id, t_philo_config *info)
{
	if (info->num_of_eat == info->eat_times)
	{
		ft_msleep(info->time_to_eat + get_time_ms());
		sem_print(philo_id, "has finished eating", info);
		sem_post(info->sem.fork);
		sem_post(info->sem.fork);
		sem_post(info->sem.room);
		return (1);
	}
	return (0);
}

static int	eating(int philo_id, t_philo_config *info)
{
	sem_wait(info->sem.room);
	sem_wait(info->sem.fork);
	if (sem_print(philo_id, "has taken a fork", info))
		return (1);
	sem_wait(info->sem.fork);
	sem_wait(info->philo_sem);
	info->last_eat = get_time_ms();
	sem_post(info->philo_sem);
	if (sem_print(philo_id, "has taken a fork", info) || \
		sem_print(philo_id, "is eating", info))
		return (1);
	if (info->eat_flag)
	{
		sem_wait(info->philo_sem);
		info->num_of_eat++;
		sem_post(info->philo_sem);
		if (check_eat_times(philo_id, info))
			return (1);
	}
	ft_msleep(info->time_to_eat + get_time_ms());
	sem_post(info->sem.fork);
	sem_post(info->sem.fork);
	sem_post(info->sem.room);
	return (0);
}

void	philo_routine(int philo_id, t_philo_config *info)
{
	while (1)
	{
		if (eating(philo_id, info))
			return ;
		if (sleeping_and_thinking(philo_id, info))
			return ;
	}
}
