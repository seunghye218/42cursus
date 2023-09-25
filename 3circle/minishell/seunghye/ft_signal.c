/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:27:05 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/08 17:07:44 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ori_handler(int signum)
{
	if (signum == SIGINT)
		printf("minishell$ \n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	newline_sigint(int n)
{
	(void)n;
	ft_putstr_fd("^C\n", 2);
}

void	sigquit_handle(int n)
{
	extern t_pid	g_pid;
	int				i;

	(void)n;
	i = 0;
	while (i < g_pid.size)
	{
		kill(g_pid.pid[i], SIGQUIT);
		i++;
	}
	if (i)
		ft_putstr_fd("^\\Quit: 3\n", 2);
}
