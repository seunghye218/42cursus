/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:00:32 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:08:42 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	result;
	size_t	temp;

	sign = 1;
	result = 0;
	temp = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == '0')
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
