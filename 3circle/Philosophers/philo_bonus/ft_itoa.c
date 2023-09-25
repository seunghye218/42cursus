/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:23:17 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/29 12:26:05 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	if (!size)
		return (src_size);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_size);
}

static char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

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
