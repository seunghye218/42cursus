/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:20:50 by seungpar          #+#    #+#             */
/*   Updated: 2022/08/31 19:09:25 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*make_envs(char **envp)
{
	int		i;
	t_list	*head;
	t_list	*cur;

	head = NULL;
	cur = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(envp[i])));
		++i;
	}
	return (head);
}
