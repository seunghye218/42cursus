/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:33:14 by seungpar          #+#    #+#             */
/*   Updated: 2022/08/31 19:07:57 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_redirection(char *str)
{
	if (str[0] != '\0' && str[0] == '<' && str[1] == '\0')
		return (1);
	if (str[0] != '\0' && str[0] == '>' && str[1] == '\0')
		return (1);
	if (str[0] != '\0' && str[0] == '<'
		&& str[1] != '\0' && str[1] == '<' && str[2] == '\0')
		return (1);
	if (str[0] != '\0' && str[0] == '>'
		&& str[1] != '\0' && str[1] == '>' && str[2] == '\0')
		return (1);
	return (0);
}

static int	is_pipe(char *str)
{
	if (str[0] != '\0' && str[0] == '|' && str[1] == '\0')
		return (1);
	return (0);
}

static t_token	*make_token(char *str, int type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->type = type;
	token->content = ft_strdup(str);
	token->next = NULL;
	return (token);
}

void	add_tokens(t_token **token_list, char **splited)
{
	int	i;
	int	is_cmd;

	i = 0;
	is_cmd = 1;
	while (splited[i] != NULL)
	{
		if (is_redirection(splited[i]))
			token_list[i] = make_token(splited[i], REDIR_TOKEN);
		else if (is_cmd)
		{
			is_cmd = 0;
			token_list[i] = make_token(splited[i], CMD_TOKEN);
		}
		else if (is_pipe(splited[i]))
		{
			is_cmd = 1;
			token_list[i] = make_token(splited[i], PIPE_TOKEN);
		}
		else
			token_list[i] = make_token(splited[i], WORD_TOKEN);
		++i;
	}
}
