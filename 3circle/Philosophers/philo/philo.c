/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:01:46 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/26 20:39:19 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	main_clear(t_philo_config *info);

int	main(int ac, char **av)
{
	static t_philo_config	info;

	if (parsing_and_check_arg(ac, av, &info))
		return (EXIT_FAILURE);
	if (a_philo(&info))
		return (0);
	if (init_config(&info))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&info.mutex.start);
	if (create_thread(&info))
		return (EXIT_FAILURE);
	init_start_time(&info);
	pthread_mutex_unlock(&info.mutex.start);
	if (info.eat_flag)
		monitoring_eat_times(&info, 0);
	else
		monitoring(&info, 0);
	join_thread(&info);
	main_clear(&info);
	return (0);
}

static void	main_clear(t_philo_config *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->mutex.mutex);
	pthread_mutex_destroy(&info->mutex.start);
	pthread_mutex_destroy(&info->mutex.dead);
	pthread_mutex_destroy(&info->mutex.time);
	pthread_mutex_destroy(&info->mutex.eat);
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->fork[i++]);
	free(info->philo);
	free(info->thr);
	free(info->fork);
}

void	*philo(void *philo_config_arg)
{
	int				philo_id;
	t_philo_config	*info;

	info = (t_philo_config *)philo_config_arg;
	init_philo(&philo_id, info);
	pthread_mutex_lock(&info->mutex.start);
	pthread_mutex_unlock(&info->mutex.start);
	philo_routine(philo_id, info);
	return (0);
}

int	mutex_print(int philo_id, char *str, t_philo_config *info)
{
	pthread_mutex_lock(&info->mutex.dead);
	if (info->check_dead)
	{
		pthread_mutex_unlock(&info->mutex.dead);
		return (1);
	}
	else
	{
		printf("%d %d %s\n", \
		get_time_ms() - info->start_time, philo_id + 1, str);
		pthread_mutex_unlock(&info->mutex.dead);
	}
	return (0);
}
