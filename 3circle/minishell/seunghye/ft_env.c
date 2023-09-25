/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:17:11 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 15:48:25 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_env(char **args, t_list **env)
{
	t_list	*tmp;

	if (!env)
		return (1);
	(void)args;
	tmp = *env;
	while (tmp)
	{
		if (!ft_strchr(tmp->content, '='))
			;
		else
			ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	return (0);
}
