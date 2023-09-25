/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:44:25 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/27 20:56:52 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static int		send_signal(pid_t server_pid, char *str);
static void		handler(int signo);
static size_t	ft_strlen(char *str);

int	main(int ac, char **av)
{
	pid_t			server_pid;

	if (ac != 3)
	{
		write(2, "arg error\n", 10);
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, handler);
	server_pid = ft_atoi(av[1]);
	if (server_pid < 100 || server_pid > 100000)
	{
		write(2, "invalid pid\n", 12);
		return (EXIT_FAILURE);
	}
	write(1, "strlen : ", 9);
	ft_putnbr(ft_strlen(av[2]), 1);
	write(1, "\n", 1);
	send_signal(server_pid, av[2]);
	write(1, "\n", 1);
	return (0);
}

static void	handler(int signo)
{
	static int	cnt;
	static char	i;

	if (1 || signo)
		;
	i++;
	if (i == 8)
	{
		i = 0;
		cnt++;
		ft_putnbr(cnt, 1);
		write(1, " ", 1);
	}
}

static int	send_signal(pid_t server_pid, char *str)
{
	unsigned char	bit;

	while (*str)
	{
		bit = 0b10000000;
		while (bit > 0)
		{
			if (*str & bit)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			pause();
			usleep(20);
			bit >>= 1;
		}
		str++;
	}
	return (0);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
