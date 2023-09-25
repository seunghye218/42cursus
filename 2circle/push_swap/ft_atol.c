/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:00:32 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/13 21:43:48 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_i(const char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		*sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

long long	ft_atol(const char *str)
{
	int			sign;
	int			i;
	long long	result;
	long long	temp;

	sign = 1;
	result = 0;
	temp = 0;
	i = get_i(str, &sign);
	while (ft_isdigit(str[i]))
	{
		result = 10 * result + str[i] - '0';
		i++;
	}
	if (str[i])
		return (0);
	return (result * sign);
}
