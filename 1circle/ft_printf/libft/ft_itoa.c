/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:08:53 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/11 21:08:04 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit_div(int *n, int *div)
{
	size_t		digit;

	digit = 0;
	if (*n < 0)
	{
		digit++;
		*n *= -1;
	}
	*div = 1;
	while (*n / *div > 9 && ++digit)
		*div *= 10;
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	int			div;
	int			sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	sign = 1;
	if (n < 0 && ++i)
		sign *= -1;
	str = (char *)malloc(sizeof(char) * (get_digit_div(&n, &div) + 1));
	if (!str)
		return (0);
	if (sign == -1)
		str[0] = '-';
	while (div != 0)
	{
		str[i++] = '0' + (n / div) % 10;
		div /= 10;
	}
	str[i] = 0;
	return (str);
}
