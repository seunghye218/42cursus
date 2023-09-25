/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_consequtive_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:26:21 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 16:04:35 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_quotes_consequtive_string(char *line)
{
	char	sc;
	int		sentence_cnt;

	sentence_cnt = 0;
	sc = 0;
	while (*line != '\0')
	{
		if ((*line == '\'' || *line == '\"') && sc == 0)
			sc = *line;
		else if ((*line == '\'' || *line == '\"') && sc == *line)
		{
			++sentence_cnt;
			sc = 0;
		}
		++line;
	}
	if (sc > 0)
		return (0);
	return (1);
}

char	*process_consequtive_string(char *line, t_list *envs, unsigned char *s)
{
	int		i;
	char	*ret;
	char	**splited;

	ret = NULL;
	splited = make_splited_str(line, 1);
	i = -1;
	while (splited[++i] != NULL)
	{
		if (include_single_quotes(splited[i]))
			splited[i] = remove_quotes(splited[i]);
		else if (include_double_quotes(splited[i]))
		{
			splited[i] = remove_quotes(splited[i]);
			splited[i] = expand_env(splited[i], envs, s);
		}
		else
			splited[i] = expand_env(splited[i], envs, s);
	}
	ret = get_strjoin_value(splited);
	free_splited_str(&splited);
	free(line);
	return (ret);
}
