/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:18:39 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 15:42:40 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	greedy_sort(t_list **a, t_list **b, int len)
{
	trans_to_index(*a);
	push_b(a, b, len);
	push_a(a, b, len);
}

int	get_chunk(int len)
{
	if (len < 101)
		return (17);
	else if (len < 501)
		return (30);
	else if (len < 1000)
		return (45);
	else if (len < 2000)
		return (65);
	else if (len < 5000)
		return (100);
	else
		return (150);
}

void	push_b(t_list **a, t_list **b, int len)
{
	int		chunk;
	int		cnt;

	chunk = get_chunk(len);
	cnt = 0;
	while (*a)
	{
		if ((*a)->n <= cnt)
		{
			p_logic(b, a, 'b');
			cnt++;
		}
		else if ((*a)->n <= cnt + chunk)
		{
			p_logic(b, a, 'b');
			r_logic(b, 'b');
			cnt++;
		}
		else
			r_logic(a, 'a');
	}
}

void	push_a(t_list **a, t_list **b, int len)
{
	t_list	*tmp;
	int		i;

	while (*b)
	{
		len--;
		tmp = *b;
		i = 0;
		while (tmp && tmp->n != len && ++i)
			tmp = tmp->next;
		if (i < len / 2)
		{
			while ((*b)->n != len)
				r_logic(b, 'b');
			p_logic(a, b, 'a');
		}
		else
		{
			while ((*b)->n != len)
				rr_logic(b, 'b');
			p_logic(a, b, 'a');
		}
	}
}
