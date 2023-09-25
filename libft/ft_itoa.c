/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:23:17 by seunghye          #+#    #+#             */
/*   Updated: 2021/11/30 17:32:34 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(long long *nb, long long *div)
{
	int			digit;

	digit = 0;
	if (*nb < 0)
	{
		*nb *= -1;
		digit++;
	}
	while (*nb / *div)
	{
		*div *= 10;
		digit++;
	}
	*div /= 10;
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			digit;
	int			i;
	long long	div;
	long long	nb;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	div = 1;
	digit = get_digit(&nb, &div);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (0);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (i < digit)
	{
		str[i++] = nb / div + '0';
		nb %= div;
		div /= 10;
	}
	str[i] = 0;
	return (str);
}
