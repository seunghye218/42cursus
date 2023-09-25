/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:24:34 by kimseunghye       #+#    #+#             */
/*   Updated: 2021/12/06 17:27:48 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	if (dst_size + 1 < size)
	{
		i = 0;
		while (dst_size + i + 1 < size && src[i])
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i] = 0;
	}
	return (dst_size + src_size);
}
