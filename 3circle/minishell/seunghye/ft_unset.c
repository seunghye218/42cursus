/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:25:01 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 15:20:23 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	check_name(char *name)
{
	int	i;

	if (!name)
		return (1);
	i = 0;
	while (name[i] && (name[i] == '_' || ft_isalnum(name[i])))
		i++;
	if (ft_isdigit(*name) || name[i])
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	return (0);
}

int	ft_unset(char **args, t_list **env)
{
	t_list	*pre;
	int		i;
	int		status;

	i = 1;
	status = 0;
	while (args[i])
	{
		if (check_name(args[i]))
		{
			status = 2;
			i++;
			continue ;
		}
		pre = get_val_cmp_pre(*env, args[i]);
		if (pre == (void *)-1)
			lstdel_node(env, *env);
		else if (pre)
			lstdel_node(env, pre->next);
		i++;
	}
	return (status);
}
