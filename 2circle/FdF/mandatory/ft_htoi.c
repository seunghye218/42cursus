/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:39:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:49:47 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

static int	ft_ishex(int c)
{
	return (((unsigned)c | 32) - 'a' < 6);
}

int	ft_htoi(char *str)
{
	size_t	result;
	char	c;

	result = 0;
	str += 2;
	while (ft_isdigit(*str) || ft_ishex(*str))
	{
		c = *str;
		if (ft_ishex(*str))
		{
			if (*str == 70)
				c -= 55;
			else
				c -= 87;
		}
		else
			c -= '0';
		result <<= 4;
		result += c;
		str++;
	}
	return ((int)result);
}
