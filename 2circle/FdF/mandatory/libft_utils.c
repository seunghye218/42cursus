/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:59:52 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:50:01 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (str);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

static char	*ft_strdup(const char *s1)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size_1;
	size_t	size_2;

	if (!s2)
		ft_exit("strjoin() arg error");
	if (!s1)
	{
		str = ft_strdup(s2);
		if (!str)
			ft_exit("strjoin() malloc() error");
		free(s2);
		return (str);
	}
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size_1 + size_2 + 1));
	if (!str)
		ft_exit("strjoin() malloc() error");
	ft_strlcpy(str, s1, size_1 + 1);
	ft_strlcpy(str + size_1, s2, size_2 + 1);
	free(s1);
	free(s2);
	return (str);
}
