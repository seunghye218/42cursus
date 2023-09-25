/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:25:05 by seungpar          #+#    #+#             */
/*   Updated: 2022/02/17 20:22:37 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_number_len(long l, const char *base);

char	*ft_itoa_base(int n, const char *base)
{
	char	*str;
	size_t	num_len;
	size_t	base_len;
	long	l;
	size_t	bottom;

	bottom = 0;
	l = n;
	num_len = ft_get_number_len(l, base);
	base_len = ft_strlen(base);
	str = ft_calloc(num_len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		l *= -1;
		str[0] = '-';
		bottom++;
	}
	while (num_len != bottom)
	{
		str[--num_len] = base[l % base_len];
		l /= base_len;
	}
	return (str);
}

static size_t	ft_get_number_len(long l, const char *base)
{
	size_t			len;
	size_t			base_len;
	unsigned long	ul;

	len = 1;
	if (l < 0)
	{
		ul = l * -1;
		len++;
	}
	else
		ul = l;
	base_len = ft_strlen(base);
	while (ul >= base_len)
	{
		ul /= base_len;
		len++;
	}
	return (len);
}
