/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:59:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/27 20:19:25 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_char	g_c;

static void	handler_info_one(int signo, siginfo_t *info, void *p);
static void	handler_info_two(int signo, siginfo_t *info, void *p);

int	main(void)
{
	struct sigaction	s_act1;
	struct sigaction	s_act2;

	g_c.i = 0;
	g_c.c = 0;
	s_act1.sa_flags = SA_SIGINFO;
	s_act2.sa_flags = SA_SIGINFO;
	s_act1.sa_sigaction = handler_info_one;
	s_act2.sa_sigaction = handler_info_two;
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &s_act1, 0);
	sigaction(SIGUSR2, &s_act2, 0);
	while (1)
		pause();
	return (0);
}

static void	handler_info_one(int signo, siginfo_t *info, void *p)
{
	pid_t	client_pid;

	if (1 || signo || p)
		;
	client_pid = info->si_pid;
	g_c.c <<= 1;
	g_c.i++;
	if (g_c.i == 8)
	{
		write(1, &g_c.c, 1);
		g_c.i = 0;
		g_c.c = 0;
	}
	usleep(20);
	kill(client_pid, SIGUSR1);
}

static void	handler_info_two(int signo, siginfo_t *info, void *p)
{
	pid_t	client_pid;

	if (1 || signo || p)
		;
	client_pid = info->si_pid;
	g_c.c <<= 1;
	g_c.c |= 1;
	g_c.i++;
	if (g_c.i >= 8)
	{
		write(1, &g_c.c, 1);
		g_c.i = 0;
		g_c.c = 0;
	}
	usleep(20);
	kill(client_pid, SIGUSR1);
}
