/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:41:11 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 14:39:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_cd(char **args, t_list **env)
{
	(void)env;
	if (!args)
		return (1);
	if (!args[1])
		return (2);
	if (chdir(args[1]) == -1)
		return (1);
	return (0);
}
