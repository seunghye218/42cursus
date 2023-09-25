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

static int	check_dead(t_philo_config *info, int i)
{
	pthread_mutex_lock(&info->mutex.dead);
	pthread_mutex_lock(&info->mutex.time);
	if (get_time_ms() - info->philo[i].last_eat >= info->time_to_die)
	{
		pthread_mutex_unlock(&info->mutex.time);
		printf("%d %d died\n", get_time_ms() - info->start_time, i + 1);
		info->check_dead = 1;
		pthread_mutex_unlock(&info->mutex.dead);
		return (1);
	}
	pthread_mutex_unlock(&info->mutex.time);
	pthread_mutex_unlock(&info->mutex.dead);
	return (0);
}

static int	check_eat_times(t_philo_config *info, int *i, char *arr)
{
	if (arr[*i])
	{
		*i += 1;
		return (1);
	}
	pthread_mutex_lock(&info->mutex.eat);
	if (info->philo[*i].num_of_eat == info->eat_times)
	{
		arr[*i] = 1;
		*i += 1;
		pthread_mutex_unlock(&info->mutex.eat);
		return (1);
	}
	pthread_mutex_unlock(&info->mutex.eat);
	return (0);
}

static char	*init_monitoring(int num_of_philo)
{
	char	*arr;

	arr = malloc(sizeof(char) * num_of_philo + 1);
	if (!arr)
	{
		printf("eat_times_arr malloc error\n");
		return (arr);
	}
	memset(arr, 0, num_of_philo + 1);
	return (arr);
}

void	monitoring_eat_times(t_philo_config *info, int i)
{
	char	*arr;

	arr = init_monitoring(info->num_of_philo);
	if (!arr)
		return ;
	while (1)
	{
		if (ft_strlen(arr) == info->num_of_philo)
		{
			free(arr);
			return ;
		}
		i = 0;
		while (i < info->num_of_philo)
		{
			if (check_eat_times(info, &i, arr))
				continue ;
			if (check_dead(info, i))
				return ;
			i++;
		}
	}
}

void	monitoring(t_philo_config *info, int i)
{
	while (1)
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			if (check_dead(info, i))
				return ;
			i++;
		}
	}
}
