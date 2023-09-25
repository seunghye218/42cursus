/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:19:21 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 13:13:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int n)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		exit(EXIT_FAILURE);
	lst->n = n;
	lst->next = 0;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		exit(EXIT_FAILURE);
	if (!new)
		exit(EXIT_FAILURE);
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	ft_lstlast(*lst)->next = new;
	return (1);
}
