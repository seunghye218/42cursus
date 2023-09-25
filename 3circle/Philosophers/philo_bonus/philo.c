/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:01:46 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/29 12:35:53 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_config	info;
	pid_t			pid;

	if (parsing_and_check_arg(ac, av, &info))
		return (EXIT_FAILURE);
	info.sem_name = init_sem_name(info.num_of_philo);
	sem_clear(info);
	init_config(&info);
	pid = create_philo(&info);
	if (pid == 0)
		philo(&info);
	else
	{
		wait_child_end(&info);
		main_clear(&info);
	}
	return (0);
}

void	philo(t_philo_config *info)
{
	init_philo(info);
	philo_routine(info->philo_id, info);
	philo_clear(info);
}

int	sem_print(int philo_id, char *str, t_philo_config *info)
{
	sem_wait(info->sem.dead);
	printf("%d %d %s\n", \
	get_time_ms() - info->start_time, philo_id + 1, str);
	sem_post(info->sem.dead);
	return (0);
}
