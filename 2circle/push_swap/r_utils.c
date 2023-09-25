/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:30:36 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/19 21:27:40 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	r_logic(t_list **a, char c)
{
	t_list	*end;
	t_list	*second;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == 'r')
		write(1, "rr\n", 3);
	if (!*a || !(*a)->next)
		return ;
	else if (!(*a)->next->next)
	{
		s_logic(a, 0);
		return ;
	}
	second = (*a)->next;
	end = *a;
	while (end->next)
		end = end->next;
	end->next = *a;
	(*a)->next = 0;
	*a = second;
}

void	rr(t_list **a, t_list **b, char c)
{
	r_logic(a, c);
	r_logic(b, 0);
}
