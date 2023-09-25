/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:20:46 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/02 13:26:08 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	start_str_is_pipe(char **splited)
{
	if (splited[0][0] == '|')
		return (1);
	return (0);
}

static int	last_str_is_pipe(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
		++i;
	if (splited[i - 1][0] == '|')
		return (1);
	return (0);
}

static int	redirection_word_is_missing(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		if ((splited[i][0] == '<' && splited[i][1] == '<')
			&& (splited[i + 1] == NULL || splited[i + 1][0] == '|'))
			return (1);
		else if ((splited[i][0] == '<')
			&& (splited[i + 1] == NULL || splited[i + 1][0] == '|'))
			return (1);
		else if ((splited[i][0] == '>' && splited[i][1] == '>')
			&& (splited[i + 1] == NULL || splited[i + 1][0] == '|'))
			return (1);
		else if ((splited[i][0] == '>')
			&& (splited[i + 1] == NULL || splited[i + 1][0] == '|'))
			return (1);
		++i;
	}
	return (0);
}

int	syntax_check(char **splited)
{
	if (start_str_is_pipe(splited) || last_str_is_pipe(splited)
		|| redirection_word_is_missing(splited))
		return (1);
	return (0);
}
