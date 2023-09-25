/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:22:55 by seunghye          #+#    #+#             */
/*   Updated: 2021/12/08 16:20:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (c != *set && *set)
		set++;
	return (c == *set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;
	size_t	del_size;
	size_t	suf;

	if (!s1 || !set)
		return (0);
	size = ft_strlen(s1);
	del_size = 0;
	while (is_set(*s1, set) && *s1)
	{
		del_size++;
		s1++;
	}
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	suf = ft_strlen(s1) - 1;
	while (is_set(s1[suf--], set))
		del_size++;
	size -= del_size;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size + 1);
	return (str);
}
