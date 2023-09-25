/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:10:00 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 16:20:59 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	line_handle(t_list **a, t_list **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		s_logic(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		s_logic(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		p_logic(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		p_logic(b, a, 0);
	else if (!ft_strcmp(line, "ra\n"))
		r_logic(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		r_logic(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rr_logic(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rr_logic(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
}

static void	action_line(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line_handle(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		len;

	if (ac < 2)
		return (0);
	a = parsing(ac, av, 1);
	b = 0;
	if (ac == 2 && (ft_lstsize(a) == 1))
		return (0);
	check_dup(a);
	len = ft_lstsize(a);
	action_line(&a, &b);
	if (check_sort(a, len) && !b)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	write(1, "KO\n", 3);
	return (0);
}
