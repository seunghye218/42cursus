/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:40:08 by seunghye          #+#    #+#             */
/*   Updated: 2021/12/20 23:55:52 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_size;

	if (!*needle)
		return ((char *)haystack);
	n_size = ft_strlen(needle);
	while (*haystack && len-- >= n_size)
	{
		i = 0;
		if (*haystack == *needle)
		{
			while (needle[i] && *(haystack + i) == needle[i])
				i++;
		}
		if (i == n_size)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
