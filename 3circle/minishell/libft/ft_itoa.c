/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:48:10 by seungpar          #+#    #+#             */
/*   Updated: 2021/12/05 17:47:05 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_get_num_len(int n);
static char		*ft_sub_itoa(int n, char *ret, size_t len);

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;

	len = ft_get_num_len(n);
	if (n > 0)
		ret = (char *)malloc(len + 1);
	else
		ret = (char *)malloc(len + 2);
	if (!ret)
		return (NULL);
	if (n == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	return (ft_sub_itoa(n, ret, len));
}

static size_t	ft_get_num_len(int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_sub_itoa(int n, char *ret, size_t len)
{
	size_t	i;
	long	l;

	l = (long)n;
	i = 0;
	if (l < 0)
	{
		l *= -1;
		len += 1;
		ret[0] = '-';
	}
	ret[len] = '\0';
	while (l)
	{
		i++;
		ret[len - i] = l % 10 + '0';
		l /= 10;
	}
	return (ret);
}
