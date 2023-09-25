/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:22:12 by seungpar          #+#    #+#             */
/*   Updated: 2021/12/05 17:37:06 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_word_count(char const *p, char const c);
static void			ft_all_free(char **pp);
static char const	*ft_get_start_pos(char const *p, char const c);
static char const	*ft_get_end_pos(char const *p, char const c);

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**ret;
	char const	*end;
	size_t		word_count;

	word_count = ft_get_word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		s = ft_get_start_pos(s, c);
		end = ft_get_end_pos(s, c);
		ret[i] = ft_substr(s, 0, end - s);
		if (!ret[i])
		{
			ft_all_free(ret);
			return (NULL);
		}
		i++;
		s = end;
	}
	ret[i] = NULL;
	return (ret);
}

static char const	*ft_get_start_pos(char const *p, char const c)
{
	while (*p && *p == c)
		p++;
	return (p);
}

static char const	*ft_get_end_pos(char const *p, char const c)
{
	while (*p && *p != c)
		p++;
	return (p);
}

static size_t	ft_get_word_count(char const *p, char const c)
{
	size_t	cnt;

	cnt = 0;
	while (*p)
	{
		if (*p != c)
		{
			cnt++;
			while (*p && *p != c)
				p++;
		}
		else
			p++;
	}
	return (cnt);
}

static void	ft_all_free(char **pp)
{
	while (*pp)
	{
		free(*pp);
		*pp++ = NULL;
	}
	free(pp);
	pp = NULL;
}
