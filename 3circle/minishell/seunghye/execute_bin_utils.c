/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:08:05 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/08 16:15:59 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	check_args(char **args)
{
	if (!args)
		return (1);
	if (*args[0] == '.' && ft_strlen(args[0]) == 1)
		return (1);
	return (0);
}

int	bin_exception(char **args)
{
	if (!args)
		return (0);
	if (*args[0] == '.' && ft_strlen(args[0]) == 1)
	{
		ft_putstr_fd(".: filename argument required\n\
.: usage: . filename [arguments]\n", 2);
		return (2);
	}
	return (0);
}
