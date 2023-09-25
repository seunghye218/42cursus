/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:10:37 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 11:26:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	s_logic(t_list **a, char c)
{
	t_list	*second;

	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	else if (c == 's')
		write(1, "ss\n", 3);
	if (!*a || !(*a)->next)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
}

void	ss(t_list **a, t_list **b, char c)
{
	s_logic(a, c);
	s_logic(b, 0);
}
