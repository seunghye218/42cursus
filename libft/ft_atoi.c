/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:00:32 by seunghye          #+#    #+#             */
/*   Updated: 2021/12/16 17:52:29 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;
	long long	temp;

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
