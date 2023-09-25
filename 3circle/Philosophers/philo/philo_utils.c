/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:07:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/27 12:15:46 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sleeping_and_thinking(int philo_id, t_philo_config *info)
{
	if (mutex_print(philo_id, "is sleeping", info))
		return (1);
	ft_msleep(info->time_to_sleep + get_time_ms());
	if (mutex_print(philo_id, "is thinking", info))
		return (1);
	return (0);
}

static int	check_eat_times(int philo_id, t_philo_config *info, t_philo *philo)
{
	if (philo->num_of_eat == info->eat_times)
	{
		ft_msleep(info->time_to_eat + get_time_ms());
		mutex_print(philo_id, "has finished eating", info);
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		return (1);
	}
	return (0);
}

int	eating(int philo_id, t_philo_config *info, t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	if (mutex_print(philo_id, "has taken a fork", info))
		return (1);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(&info->mutex.time);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&info->mutex.time);
	if (mutex_print(philo_id, "has taken a fork", info) || \
		mutex_print(philo_id, "is eating", info))
		return (1);
	if (info->eat_flag)
	{
		pthread_mutex_lock(&info->mutex.eat);
		philo->num_of_eat++;
		pthread_mutex_unlock(&info->mutex.eat);
		if (check_eat_times(philo_id, info, philo))
			return (1);
	}
	ft_msleep(info->time_to_eat + get_time_ms());
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (0);
}

void	philo_routine(int philo_id, t_philo_config *info)
{
	int	odd_sleep;

	odd_sleep = \
	(info->time_to_die - info->time_to_eat - info->time_to_sleep) * 512;
	while (1)
	{
		if (philo_id % 2 == 0)
			usleep(500);
		if (eating(philo_id, info, &info->philo[philo_id]))
			return ;
		if (sleeping_and_thinking(philo_id, info))
			return ;
		if (info->num_of_philo % 2)
			usleep(odd_sleep);
		else
			usleep(300);
	}
}
