/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:54:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 14:26:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

t_list	*get_val_cmp_pre(t_list *lst, char *value)
{
	if (!lst)
		return (0);
	if (lst && !ft_strncmp(value, lst->content, ft_strlen(value)))
		return ((void *)-1);
	while (lst->next && ft_strncmp(value, lst->next->content, ft_strlen(value)))
		lst = lst->next;
	if (!lst->next)
		return (0);
	return (lst);
}

t_list	*get_pre_node(t_list *lst, t_list *node)
{
	if (!lst)
		return (0);
	if (lst == node)
		return ((void *)-1);
	while (lst->next && lst->next != node)
		lst = lst->next;
	if (!lst->next)
		return (0);
	return (lst);
}

void	lstdel_node(t_list **lst, t_list *node)
{
	t_list	*pre;
	t_list	*next;

	pre = get_pre_node(*lst, node);
	if (!pre)
		return ;
	if (pre == (void *)-1)
	{
		*lst = (*lst)->next;
		ft_lstdelone(node, free);
		return ;
	}
	next = node->next;
	ft_lstdelone(node, free);
	pre->next = next;
}

char	**get_envp(t_list *env)
{
	char	**envp;
	int		i;
	int		n;

	n = ft_lstsize(env);
	if (n == 0)
		return (0);
	envp = malloc(sizeof(char *) * (n + 1));
	if (!envp)
		return (0);
	i = -1;
	while (++i < n)
	{
		if (!ft_strchr(env->content, '='))
		{
			envp[i] = ft_strdup("");
			continue ;
		}
		envp[i] = ft_strdup(env->content);
		if (!envp[i])
			return (0);
		env = env->next;
	}
	envp[i] = 0;
	return (envp);
}
