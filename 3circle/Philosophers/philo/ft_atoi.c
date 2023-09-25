/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:00:32 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/21 13:03:40 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	result;
	size_t	temp;

	sign = 1;
	result = 0;
	temp = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		temp = 10 * result + *str - '0';
		if (sign == 1 && temp < result)
			return (-1);
		if (sign == -1 && temp < result)
			return (0);
		result = temp;
		str++;
	}
	return ((int)result * sign);
}
