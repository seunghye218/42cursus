/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:25:47 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/06 17:42:42 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_pipe_count(t_token **tokens)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i]->type == PIPE_TOKEN)
			++cnt;
		++i;
	}
	return (cnt);
}

static void	add_last(t_token **cmds, int size, t_token *new)
{
	t_token	*cur;

	if (cmds[size] == NULL)
		cmds[size] = new;
	else
	{
		cur = cmds[size];
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

void	init_info(t_info *info, t_token **tokens)
{
	int		size;
	int		i;
	t_token	*prev;

	info->size = get_pipe_count(tokens) + 1;
	info->cmds = ft_calloc(info->size + 1, sizeof(t_token *));
	size = 0;
	i = 0;
	prev = NULL;
	while (tokens[i] != NULL)
	{
		if (tokens[i]->type == PIPE_TOKEN)
		{
			++size;
			++i;
			continue ;
		}
		add_last(info->cmds, size, tokens[i++]);
	}
}
