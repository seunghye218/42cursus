/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:26:42 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 19:58:06 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <signal.h>

static void	signal_handler(int signal)
{
	if (signal == SIGINT)
		printf("minishell$ \n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	setting_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	process_signal_ctrl_d(int return_value)
{
	printf("\033[1A");
	printf("\033[10C");
	printf(" exit\n");
	exit(return_value);
}

void	heredoc_handler(int signal)
{
	if (signal == SIGINT)
	{
		unlink_heredoc_files();
		exit(1);
	}
}

void	tmp_handler(int signal)
{
	if (signal == SIGINT)
		printf("\n");
}
