/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:48:18 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 12:55:21 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_dup(t_list *lst)
{
	t_tree	*root;

	root = tree_new(lst->n);
	lst = lst->next;
	while (lst)
	{
		tree_insert(root, lst->n);
		lst = lst->next;
	}
	tree_clear(root);
	root = 0;
}

t_tree	*tree_new(int n)
{
	t_tree	*node;

	node = (t_tree *)malloc(sizeof(t_tree));
	if (!node)
		exit(EXIT_FAILURE);
	node->n = n;
	node->l = 0;
	node->r = 0;
	return (node);
}

void	tree_insert(t_tree *node, int n)
{
	while (node)
	{
		if (n < node->n)
		{
			if (!(node->l))
			{
				node->l = tree_new(n);
				return ;
			}
			node = node->l;
		}
		else if (n > node->n)
		{
			if (!(node->r))
			{
				node->r = tree_new(n);
				return ;
			}
			node = node->r;
		}
		else
			ft_exit();
	}
}

void	tree_clear(t_tree *node)
{
	if (node->l)
		tree_clear(node->l);
	if (node->r)
		tree_clear(node->r);
	free(node);
}
