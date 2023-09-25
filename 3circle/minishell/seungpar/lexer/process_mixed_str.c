/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mixed_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:23:06 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 16:03:06 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_mixed_quotes(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\'' || *s == '\"')
			return (1);
		s++;
	}
	return (0);
}

static void	sub_func(char *s, char **splited)
{
	int		i;
	int		c;
	int		cnt;
	int		start;

	cnt = 0;
	start = 0;
	c = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (c == 0 && (s[i] == '\'' || s[i] == '\"'))
		{
			c = s[i];
			splited[cnt++] = ft_substr(s, start, i - start);
			start = i;
		}
		else if (c != 0 && s[i] == c)
		{
			c = 0;
			splited[cnt++] = ft_substr(s, start, i - start + 1);
			start = i + 1;
		}
	}
	splited[cnt++] = ft_substr(s, start, i - start + 1);
}

char	*process_mixed_str(char *s, t_list *envs, unsigned char *st)
{
	int		i;
	char	**splited;
	char	*ret;

	splited = ft_calloc(1000, sizeof(char *));
	sub_func(s, splited);
	i = -1;
	while (splited[++i] != NULL)
	{
		if (include_single_quotes(splited[i]))
		{
			splited[i] = remove_quotes(splited[i]);
		}
		else if (include_double_quotes(splited[i]))
		{
			splited[i] = remove_quotes(splited[i]);
			splited[i] = expand_env(splited[i], envs, st);
		}
	}
	ret = get_strjoin_value(splited);
	free_splited_str(&splited);
	free(s);
	return (ret);
}
/*
 * int i
 * int c
 * int cnt
 * int start	-> int a[]
 */
