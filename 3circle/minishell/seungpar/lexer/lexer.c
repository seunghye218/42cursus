/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:35:13 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 16:02:56 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_last_empty_string(char **splited)
{
	int		i;

	i = 0;
	while (splited[i] != NULL)
		++i;
	if (splited[i - 1][0] == '\0')
	{
		free(splited[i - 1]);
		splited[i - 1] = NULL;
	}
}

t_token	**lexer(char *line, t_list *envs, unsigned char *exit_status)
{
	t_token	**token_list;
	char	**splited;

	if (have_only_one_quote(line))
		return (NULL);
	splited = make_splited_str(line, 0);
	remove_last_empty_string(splited);
	if (syntax_check(splited) != 0)
	{
		free_splited_str(&splited);
		return (NULL);
	}
	env_var_expand(splited, envs, exit_status);
	token_list = ft_calloc(1000, sizeof(t_token *));
	add_tokens(token_list, splited);
	free_splited_str(&splited);
	return (token_list);
}
