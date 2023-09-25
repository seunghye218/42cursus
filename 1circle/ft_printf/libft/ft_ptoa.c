/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:44:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/12 15:12:13 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*my_malloc(size_t digit)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (digit + 3));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[digit + 2] = 0;
	return (str);
}

static char	get_c(size_t p2, size_t div)
{
	char	c;

	if ((p2 / div) % 16 < 10)
		c = '0' + (p2 / div) % 16;
	else
		c = 'a' + ((p2 / div) % 16) - 10;
	return (c);
}

char	*ft_ptoa(void *p)
{
	char	*str;
	size_t	digit;
	size_t	i;
	size_t	p2;
	size_t	div;

	p2 = (size_t)p;
	digit = 1;
	div = 1;
	while (p2 / div > 15 && digit++)
		div *= 16;
	str = my_malloc(digit);
	if (!str)
		return (0);
	i = 2;
	while (div != 0)
	{
		str[i++] = get_c(p2, div);
		div /= 16;
	}
	return (str);
}
