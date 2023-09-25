/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:25:19 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/21 11:59:26 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_philo_config *info)
{
	int	i;

	info->thr = malloc(sizeof(pthread_t) * info->num_of_philo);
	if (!info->thr)
	{
		printf("pthread_t variable malloc error\n");
		return (1);
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_create(&info->thr[i], 0, philo, info))
		{
			printf("pthread_create error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_thread(t_philo_config *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_join(info->thr[i], 0))
		{
			printf("philo pthread_join error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
