/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:04:21 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 13:52:28 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**make_splited_str(char *line, int flag)
{
	int		start;
	int		end;
	int		i;
	int		cnt;
	char	**ret;

	ret = ft_calloc(1000, sizeof(char *));
	cnt = 0;
	start = 0;
	end = 0;
	i = 0;
	while (1)
	{
		start = get_start_pos(line, start);
		if (flag == 1)
			end = get_end_pos_flag(line, start);
		else
			end = get_end_pos(line, start);
		ret[cnt++] = ft_substr(line, start, end - start);
		if (line[end] == '\0')
			break ;
		start = end;
	}
	return (ret);
}

char	*remove_quotes(char *str)
{
	int		len;
	char	*ret;

	len = ft_strlen(str);
	ret = ft_substr(str, 1, len - 2);
	free(str);
	return (ret);
}

int	include_single_quotes(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
		return (1);
	return (0);
}

int	include_double_quotes(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '\"' && str[len - 1] == '\"')
		return (1);
	return (0);
}

void	env_var_expand(char **splited, t_list *envs, unsigned char *s)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		if (is_quotes_consequtive_string(splited[i]) == 1)
			splited[i] = process_consequtive_string(splited[i], envs, s);
		else if (include_single_quotes(splited[i]))
			splited[i] = remove_quotes(splited[i]);
		else if (include_double_quotes(splited[i]))
		{
			splited[i] = remove_quotes(splited[i]);
			splited[i] = expand_env(splited[i], envs, s);
		}
		else if (str_mixed_quotes(splited[i]))
			splited[i] = process_mixed_str(splited[i], envs, s);
		else
			splited[i] = expand_env(splited[i], envs, s);
		++i;
	}
}
