/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:34:48 by seungpar          #+#    #+#             */
/*   Updated: 2022/02/19 14:57:57 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_number_len(unsigned long l, const size_t base_len)
{
	size_t		len;

	len = 1;
	while (l >= base_len)
	{
		l /= base_len;
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long l, const char *base)
{
	char	*str;
	size_t	num_len;
	size_t	base_len;

	base_len = ft_strlen(base);
	num_len = ft_get_number_len(l, base_len);
	str = ft_calloc(num_len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (num_len != 0)
	{
		str[--num_len] = base[l % base_len];
		l /= base_len;
	}
	return (str);
}
