/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:23:09 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 18:49:39 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	check_zero(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' && *(str + 1) == 0)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	if (*str)
		return (0);
	return (1);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
}

t_list	*parsing(int ac, char **av, int i)
{
	int			j;
	char		**strs;
	long long	arg;
	t_list		*lst;

	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		if (!strs || !*strs)
			ft_exit();
		j = 0;
		while (strs[j])
		{
			arg = ft_atol(strs[j]);
			if ((arg == 0 && !check_zero(strs[j])) || \
			arg < INT_MIN || arg > INT_MAX)
				ft_exit();
			ft_lstadd_back(&lst, ft_lstnew((int)arg));
			j++;
		}
		free_strs(strs);
		free(strs);
		i++;
	}
	return (lst);
}
