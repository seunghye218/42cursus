/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:42:09 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/21 14:42:54 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead(t_philo_config *info, int philo_id)
{
	sem_wait(info->sem.dead);
	sem_wait(info->philo_sem);
	if (get_time_ms() - info->last_eat >= info->time_to_die)
	{
		sem_post(info->philo_sem);
		printf("%d %d died\n", get_time_ms() - info->start_time, philo_id + 1);
		exit(1);
	}
	sem_post(info->philo_sem);
	sem_post(info->sem.dead);
	return (0);
}

static int	check_eat_times2(t_philo_config *info)
{
	sem_wait(info->philo_sem);
	if (info->num_of_eat == info->eat_times)
	{
		sem_post(info->philo_sem);
		return (1);
	}
	sem_post(info->philo_sem);
	return (0);
}

void	*monitor(void *arg)
{
	t_philo_config	*info;
	int				philo_id;

	info = (t_philo_config *)arg;
	philo_id = info->philo_id;
	while (1)
	{
		if (info->eat_flag)
		{
			if (check_eat_times2(info))
				return (0);
		}
		if (check_dead(info, philo_id))
			return (0);
		usleep(300);
	}
	return (0);
}
