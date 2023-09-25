/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:09:10 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/19 21:28:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rr_logic(t_list **a, char c)
{
	t_list	*prend;
	t_list	*end;

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else if (c == 'r')
		write(1, "rrr\n", 4);
	if (!*a || !(*a)->next)
		return ;
	else if (!(*a)->next->next)
	{
		s_logic(a, 0);
		return ;
	}
	prend = *a;
	while (prend->next->next)
		prend = prend->next;
	end = prend->next;
	end->next = *a;
	prend->next = 0;
	*a = end;
}

void	rrr(t_list **a, t_list **b, char c)
{
	rr_logic(a, c);
	rr_logic(b, 0);
}
