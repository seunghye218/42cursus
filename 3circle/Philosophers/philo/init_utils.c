/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:49:58 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/26 20:39:00 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_config(t_philo_config *info)
{
	info->ready_philo = 0;
	info->check_dead = 0;
	if (init_fork(info))
		return (1);
	if (pthread_mutex_init(&info->mutex.mutex, 0) || \
	pthread_mutex_init(&info->mutex.start, 0) || \
	pthread_mutex_init(&info->mutex.time, 0) || \
	pthread_mutex_init(&info->mutex.eat, 0) || \
	pthread_mutex_init(&info->mutex.dead, 0))
	{
		printf("info->mutex init error\n");
		return (1);
	}
	info->philo = malloc(sizeof(t_philo) * info->num_of_philo);
	if (!info->philo)
	{	
		printf("t_philo pointer malloc error\n");
		return (1);
	}
	return (0);
}

int	init_fork(t_philo_config *info)
{
	int				i;

	info->fork = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->fork)
	{
		printf("fork malloc error\n");
		return (1);
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->fork[i], 0))
		{
			printf("fork[%d] mutex init error\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_start_time(t_philo_config *info)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&info->mutex.mutex);
		if (info->ready_philo == info->num_of_philo)
			break ;
		pthread_mutex_unlock(&info->mutex.mutex);
		usleep(100);
	}
	info->start_time = get_time_ms();
	i = 0;
	while (i < info->num_of_philo)
		info->philo[i++].last_eat = info->start_time;
	pthread_mutex_unlock(&info->mutex.start);
}

static void	take_a_fork_order(int philo_id, t_philo_config *info)
{
	int	left;
	int	right;

	left = (philo_id + info->num_of_philo) % info->num_of_philo;
	right = (philo_id + 1) % info->num_of_philo;
	if (philo_id % 2)
	{
		info->philo[philo_id].fork1 = &info->fork[left];
		info->philo[philo_id].fork2 = &info->fork[right];
	}
	else
	{
		info->philo[philo_id].fork1 = &info->fork[right];
		info->philo[philo_id].fork2 = &info->fork[left];
	}
}

void	init_philo(int *philo_id, t_philo_config *info)
{
	pthread_mutex_lock(&info->mutex.mutex);
	*philo_id = info->ready_philo;
	take_a_fork_order(*philo_id, info);
	info->philo[*philo_id].num_of_eat = 0;
	info->ready_philo++;
	pthread_mutex_unlock(&info->mutex.mutex);
}
