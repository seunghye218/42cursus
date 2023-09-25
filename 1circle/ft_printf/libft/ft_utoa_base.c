/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:44:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/12 18:23:46 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	get_c(unsigned n, unsigned div, unsigned int base, char format)
{
	char	c;

	if ((n / div) % base < 10)
		c = '0' + (n / div) % base;
	else if (format == 'X')
		c = 'A' + ((n / div) % base) - 10;
	else
		c = 'a' + ((n / div) % base) - 10;
	return (c);
}

char	*ft_utoa_base(unsigned int n, unsigned int base, char format)
{
	char			*str;
	size_t			digit;
	unsigned int	div;
	size_t			i;

	digit = 1;
	div = 1;
	while (n / div > (base - 1) && digit++)
		div *= base;
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (0);
	str[digit] = 0;
	i = 0;
	while (div != 0)
	{
		str[i++] = get_c(n, div, base, format);
		div /= base;
	}
	return (str);
}
