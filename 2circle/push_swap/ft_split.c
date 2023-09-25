/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:23:06 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 12:56:56 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_cnt(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
	}
	return (cnt);
}

static char	*get_str(char const *s, char c)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

static char	**fre(char **strs, int i)
{
	while (i >= 0)
		free(strs[i--]);
	free(strs);
	exit(EXIT_FAILURE);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		cnt;
	int		i;

	if (!s)
		return (0);
	cnt = str_cnt(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!strs)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < cnt)
	{
		while (*s == c && *s)
			s++;
		strs[i] = get_str(s, c);
		if (!strs[i])
			return (fre(strs, i));
		while (*s != c && *s)
			s++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
