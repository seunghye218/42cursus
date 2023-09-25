/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:29:41 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/08 16:03:33 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	ft_isnum(char c)
{
	return ('0' <= c && c <= '9');
}

static int	str_isnum(char *s)
{
	while (ft_isnum(*s))
		s++;
	if (*s)
		return (1);
	return (0);
}

static void	no_args(char **args, t_list **env)
{
	extern t_pid	g_pid;

	if (env)
		;
	if (!args[1])
	{
		ft_putstr_fd("exit\n", 1);
		exit(g_pid.status);
	}
}

int	ft_exit(char **args, t_list **env)
{
	extern t_pid	g_pid;
	int				size;

	no_args(args, env);
	if (str_isnum(args[1]))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	size = 1;
	while (args[size])
		size++;
	if (size > 2)
	{
		ft_putstr_fd("exit\nexit: too many arguments\n", 2);
		return (1);
	}
	exit(ft_atoi(args[1]));
	return (g_pid.status);
}
