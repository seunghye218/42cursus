/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:57:02 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 19:37:58 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	sub_expand_env(t_chunk *ck);

/*
 * n[0] = start;	ptr[0] = env_name;
 * n[1] = cnt;		ptr[1] = ret;
 * n[2] = i;		ptr[2] = tmp;
 */
char	*expand_env(char *str, t_list *env, unsigned char *status)
{
	t_chunk		chnk;

	ft_memset(&chnk, 0, sizeof(chnk));
	chnk.str = str;
	chnk.env = env;
	chnk.status = *status;
	chnk.splited = ft_calloc(1000, sizeof(char *));
	sub_expand_env(&chnk);
	if (chnk.cnt == 0)
	{
		free_splited_str(&(chnk.splited));
		return (str);
	}
	chnk.ret = get_strjoin_value(chnk.splited);
	free(str);
	free_splited_str(&(chnk.splited));
	return (chnk.ret);
}

static void	sub_sub_expand_env(t_chunk *ck)
{
	char	*env_name;

	ck->start = ck->i;
	while (!(ck->str[ck->i] == ' ' || ck->str[ck->i] == '$'
			|| ck->str[ck->i] == '\0' || ck->str[ck->i] == '\''
			|| ck->str[ck->i] == '\"' || ck->str[ck->i] == '?'))
		ck->i++;
	env_name = ft_substr(ck->str, ck->start, ck->i - ck->start);
	ck->splited[ck->cnt++] = get_env_value(env_name, ck->env,
			&ck->status);
	free(env_name);
	ck->start = ck->i;
}

static void	add_exit_status_to_splited(t_chunk *ck)
{
	ck->splited[ck->cnt++] = ft_itoa(ck->status);
	ck->i++;
	ck->start = ck->i;
}

static void	sub_expand_env_sub(t_chunk *ck)
{
	if (ck->start != ck->i)
		ck->splited[ck->cnt++] = ft_substr(ck->str, ck->start,
				ck->i - ck->start);
	ck->i++;
}

static void	sub_expand_env(t_chunk *ck)
{
	while (1)
	{
		if (ck->str[ck->i] == '$')
		{
			sub_expand_env_sub(ck);
			if (ck->str[ck->i] == '?')
			{
				add_exit_status_to_splited(ck);
				continue ;
			}
			sub_sub_expand_env(ck);
			continue ;
		}
		if (ck->str[ck->i] == '\0' && ck->start != ck->i)
		{
			ck->splited[ck->cnt++] = ft_substr(ck->str, ck->start,
					ck->i - ck->start);
			break ;
		}
		else if (ck->str[ck->i] == '\0')
			break ;
		ck->i++;
	}
}
