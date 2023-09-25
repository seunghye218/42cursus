/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:52:36 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/21 15:28:34 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	config_handle(char **av, t_philo_config *info, int i)
{
	info->eat_flag = 0;
	if (i == 1)
		info->num_of_philo = ft_atoi(av[1]);
	if (i == 2)
		info->time_to_die = ft_atoi(av[2]);
	if (i == 3)
		info->time_to_eat = ft_atoi(av[3]);
	if (i == 4)
		info->time_to_sleep = ft_atoi(av[4]);
	if (i == 5)
	{
		info->eat_times = ft_atoi(av[5]);
		info->eat_flag = 1;
	}
}

static int	check_atoi_zero(int n, int i, char **av, t_philo_config *info)
{
	if (n)
		return (0);
	if (i == 1)
	{
		printf("Invalid number_of_philosophers : %s\n", av[1]);
		return (1);
	}
	else if (i == 5)
	{
		printf("Invalid num_of_times_each_philo_must_eat : %s\n", av[5]);
		return (1);
	}
	if (*av[i] == '0')
		config_handle(av, info, i);
	else
	{	
		printf("Invalid argment : %s\n", av[i]);
		return (1);
	}
	return (0);
}

int	parsing_and_check_arg(int ac, char **av, t_philo_config *info)
{
	int	i;
	int	n;

	if (ac < 5 || ac > 6)
	{
		printf("Usage : ./philo <num_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [num_of_times_each_philo_must_eat]\n");
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n < 0)
		{
			printf("Invalid %d argment : %s\n", i, av[i]);
			return (1);
		}
		if (check_atoi_zero(n, i, av, info))
			return (1);
		else
			config_handle(av, info, i);
		i++;
	}
	return (0);
}

int	a_philo(t_philo_config *info)
{
	if (info->num_of_philo == 1)
	{
		printf("0 1 has taken a fork\n%d 1 died\n", info->time_to_die);
		return (1);
	}
	return (0);
}
