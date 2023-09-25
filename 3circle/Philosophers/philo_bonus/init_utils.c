/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:49:58 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/29 12:32:49 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t	*init_sem(char *str, unsigned int value)
{
	sem_t	*sem;

	if (value > SEM_VALUE_MAX)
	{
		printf("Invalid sem value %d\n", value);
		exit(1);
	}
	sem = sem_open((const char *)str, O_CREAT, S_IWUSR | S_IWGRP, value);
	if (sem == SEM_FAILED)
	{
		printf("%s sem_open error\n", str);
		exit(1);
	}
	return (sem);
}

char	**init_sem_name(int num_of_philo)
{
	int		i;
	char	**names;

	names = malloc(sizeof(char *) * num_of_philo);
	if (!names)
	{
		printf("init_sem_name(names) malloc error\n");
		exit(1);
	}
	i = 0;
	while (i < num_of_philo)
	{
		names[i] = ft_itoa(i);
		i++;
	}
	return (names);
}

void	init_config(t_philo_config *info)
{
	info->num_of_eat = 0;
	info->pid = malloc(sizeof(pid_t) * info->num_of_philo);
	if (!info->pid)
	{	
		printf("info->pid malloc error\n");
		exit(1);
	}
	info->sem.fork = init_sem("fork", (unsigned int)info->num_of_philo);
	if (info->num_of_philo == 1)
		info->sem.room = init_sem("room", 1);
	else
		info->sem.room = init_sem("room", (unsigned int)info->num_of_philo / 2);
	info->sem.dead = init_sem("dead", 1);
	info->start_time = get_time_ms();
	info->last_eat = get_time_ms();
}

void	init_philo(t_philo_config *info)
{
	info->philo_sem = init_sem(info->sem_name[info->philo_id], 1);
	if (pthread_create(&info->thr, 0, monitor, (void *)info))
	{
		printf("pthread_create error\n");
		exit(1);
	}
}
