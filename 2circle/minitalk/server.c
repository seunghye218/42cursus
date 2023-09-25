/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:59:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/27 20:26:29 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char	g_c;

static void	handler_one(int signo);
static void	handler_two(int signo);

int	main(void)
{
	g_c.i = 0;
	g_c.c = 0;
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler_one);
	signal(SIGUSR2, handler_two);
	while (1)
		pause();
	return (0);
}

static void	handler_one(int signo)
{
	if (1 || signo)
		;
	g_c.c <<= 1;
	g_c.i++;
	if (g_c.i == 8)
	{
		write(1, &g_c.c, 1);
		g_c.i = 0;
		g_c.c = 0;
	}
}

static void	handler_two(int signo)
{
	if (1 || signo)
		;
	g_c.c <<= 1;
	g_c.c |= 1;
	g_c.i++;
	if (g_c.i >= 8)
	{
		write(1, &g_c.c, 1);
		g_c.i = 0;
		g_c.c = 0;
	}
}
