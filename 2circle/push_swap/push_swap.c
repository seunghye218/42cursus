/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:23 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 15:41:47 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		len;

	if (ac < 2)
		return (0);
	a = parsing(ac, av, 1);
	if (ac == 2 && (ft_lstsize(a) == 1))
		return (0);
	check_dup(a);
	len = ft_lstsize(a);
	if (check_sort(a, len))
		return (0);
	b = 0;
	if (len < 6)
	{
		under_six(&a, &b, len);
		return (0);
	}
	greedy_sort(&a, &b, len);
	return (0);
}
