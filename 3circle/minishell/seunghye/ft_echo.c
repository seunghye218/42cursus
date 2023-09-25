/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:33:29 by seunghye          #+#    #+#             */
/*   Updated: 2022/08/31 18:20:06 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	check_flag(char **args, int i, int *flag)
{
	int	j;

	if (*args[i] == '-')
	{
		if (args[i][1] == 0)
		{	
			if (i == 1)
				return (1);
			return (0);
		}
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] == 0)
		{
			*flag = 1;
			return (1);
		}
	}
	return (0);
}

static int	get_args_size(char **args, t_list **env)
{
	int	i;

	if (env)
		;
	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_echo(char **args, t_list **env)
{
	int		flag;
	int		size;
	int		i;

	size = get_args_size(args, env);
	if (size == 1 && write(1, "\n", 1))
		return (0);
	i = 1;
	flag = 0;
	while (i < size && check_flag(args, i, &flag))
		i++;
	while (i < size)
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (i < size)
			write(1, " ", 1);
	}
	if (!flag)
		write(1, "\n", 1);
	return (0);
}
