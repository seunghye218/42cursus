/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 08:48:16 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/19 18:28:08 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	under_six(t_list **a, t_list **b, int len)
{
	if (len == 2 && (*a)->n > (*a)->next->n)
		s_logic(a, 'a');
	else if (len == 3)
		three_elem(a, 'a');
	else if (len == 4)
	{
		p_logic(b, a, 'b');
		three_elem(a, 'a');
		insert_elem(a, b, 4);
	}
	else if (len == 5)
	{
		trans_to_index(*a);
		if ((*a)->n == 2 && (*a)->next->n == 3 && (*a)->next->next->n == 0 && \
		(*a)->next->next->next->n == 4)
			return (exception(a));
		if ((*a)->n == 2 && (*a)->next->n == 3 && (*a)->next->next->n == 4 && \
		(*a)->next->next->next->n == 1)
			return (exception(a));
		p_logic(b, a, 'b');
		p_logic(b, a, 'b');
		three_elem(a, 'a');
		insert_elem(a, b, 4);
		insert_elem(a, b, 5);
	}
}

void	three_elem(t_list **lst, char c)
{
	const int	top = (*lst)->n;
	const int	mid = (*lst)->next->n;
	const int	bot = (*lst)->next->next->n;

	if (top > mid && mid > bot)
	{
		s_logic(lst, c);
		rr_logic(lst, c);
	}
	else if (top > mid && mid < bot && top > bot)
		r_logic(lst, c);
	else if (top > mid && mid < bot && top < bot)
		s_logic(lst, c);
	else if (top < mid && mid > bot && top > bot)
		rr_logic(lst, c);
	else if (top < mid && mid > bot && top < bot)
	{
		s_logic(lst, c);
		r_logic(lst, c);
	}
}

void	four_elem(t_list **a, t_list **b)
{
	const int	bn = (*b)->n;

	if (bn < (*a)->next->next->n)
	{
		rr_logic(a, 'a');
		p_logic(a, b, 'a');
		r_logic(a, 'a');
		r_logic(a, 'a');
	}
	else
	{
		p_logic(a, b, 'a');
		r_logic(a, 'a');
	}
}

void	five_elem(t_list **a, t_list **b)
{
	const int	bn = (*b)->n;

	if (bn < (*a)->next->next->n)
	{
		p_logic(a, b, 'a');
		s_logic(a, 'a');
		r_logic(a, 'a');
		s_logic(a, 'a');
		rr_logic(a, 'a');
	}
	else if (bn < (*a)->next->next->next->n)
	{
		rr_logic(a, 'a');
		p_logic(a, b, 'a');
		r_logic(a, 'a');
		r_logic(a, 'a');
	}
	else
	{
		p_logic(a, b, 'a');
		r_logic(a, 'a');
	}
}

void	insert_elem(t_list **a, t_list **b, int len)
{
	const int	bn = (*b)->n;

	if (bn < (*a)->n)
		return (p_logic(a, b, 'a'));
	else if (bn < (*a)->next->n)
	{
		p_logic(a, b, 'a');
		return (s_logic(a, 'a'));
	}
	else if (len == 4)
		return (four_elem(a, b));
	else if (len == 5)
		return (five_elem(a, b));
}
