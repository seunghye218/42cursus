/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:23:06 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:49:49 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		ft_exit("split() malloc error");
	ft_strlcpy(str, s, len + 1);
	return (str);
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
		ft_exit("split() malloc error : ");
	i = 0;
	while (i < cnt)
	{
		while (*s == c && *s)
			s++;
		strs[i] = get_str(s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

void	free_split(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
