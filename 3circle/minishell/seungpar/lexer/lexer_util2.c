/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:14:23 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 14:08:01 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
static int	have_one_quote(char *str)
{
	if (str[0] == '\'' || str[0] == '\"')
		return (1);
	return (0);
}

static int	is_in_quotes(char **splited, int len, int i)
{
	if ((splited[i][0] == '\'' && splited[i][len - 1] == '\'')
		|| (splited[i][0] == '\"' && splited[i][len - 1] == '\"'))
		return (1);
	return (0);
}

static int	is_correct_pair(char *s)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (c == 0 && s[i] == '\'')
			c = '\'';
		else if (c == 0 && s[i] == '\"')
			c = '\"';
		else if (c != 0 && s[i] == '\'' && c == s[i])
			c = 0;
		else if (c != 0 && s[i] == '\"' && c == s[i])
			c = 0;
	}
	if (c == 0)
		return (1);
	return (0);
}

int	have_only_one_quote(char **splited)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (splited[++i] != NULL)
	{
		len = ft_strlen(splited[i]);
		if (len == 1 && have_one_quote(splited[i]))
			return (1);
		if (is_in_quotes(splited, len, i))
			continue ;
		j = -1;
		if (is_correct_pair(splited[i]) == 0)
			return (1);
	}
	return (0);
}
*/

int	have_only_one_quote(char *line)
{
	char	st[1000];
	int		i;

	i = -1;
	while (*line != '\0')
	{
		if ((*line == '\'' || *line == '\"') && i == -1)
			st[++i] = *line;
		else if (*line == '\'' || *line == '\"')
		{
			if (st[i] == *line)
				--i;
			else if (i - 1 >= 0 && st[i - 1] == *line)
				i -= 2;
			else
				st[++i] = *line;
		}
		++line;
	}
	if (i == -1)
		return (0);
	return (1);
}
