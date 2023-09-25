/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:44:25 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/27 18:05:11 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	int	server_pid;
	int	bit;

	if (ac != 3)
		return (EXIT_FAILURE);
	server_pid = ft_atoi(av[1]);
	if (server_pid < 100 || server_pid > 100000)
		return (EXIT_FAILURE);
	while (*av[2])
	{
		bit = 128;
		while (bit > 0)
		{
			if (*av[2] & bit)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			bit >>= 1;
			usleep(100);
		}
		av[2]++;
	}
	return (0);
}
