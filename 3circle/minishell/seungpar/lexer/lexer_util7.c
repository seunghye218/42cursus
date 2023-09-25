/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:53:57 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 14:00:42 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	sub_func1(char *line, int start_index, char c)
{
	while (1)
	{
		++start_index;
		if (line[start_index] == '\0')
			return (start_index);
		else if (line[start_index] == c)
		{
			return (start_index + 1);
		}
	}
}

static int	sub_func2(char *line, int start_index, char c)
{
	if (line[start_index + 1] == c)
		return (start_index + 2);
	else
		return (start_index + 1);
}

static int	sub_func3(char *line, int start_index, char c)
{
	if (line[start_index + 1] == c)
	{
		while (1)
		{
			if (line[start_index] == ' ' || line[start_index] == '\0')
				return (start_index);
			++start_index;
		}
	}
	return (start_index + 1);
}

int	get_end_pos_flag(char *line, int start_index)
{
	char	c;

	c = line[start_index];
	if (c == '\'' || c == '\"')
		return (sub_func1(line, start_index, c));
	else if (c == '<' || c == '>')
		return (sub_func2(line, start_index, c));
	else if (c == '|')
		return (sub_func3(line, start_index, c));
	else
	{
		while (1)
		{
			if (line[start_index] == ' ' || line[start_index] == '\0'
				|| line[start_index] == '<' || line[start_index] == '>'
				|| line[start_index] == '|' || line[start_index] == '\''
				|| line[start_index] == '\"')
				return (start_index);
			++start_index;
		}
	}
}
