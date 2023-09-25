/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:50:25 by seungpar          #+#    #+#             */
/*   Updated: 2022/08/31 19:08:12 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * s = env_name
 */
char	*get_env_value(char *s, t_list *env, unsigned char *exit_status)
{
	int	j;
	int	len;

	if (s[0] != '\0' && s[0] == '?')
		return (ft_itoa(*exit_status));
	while (env != NULL)
	{
		j = 0;
		while (((char *)(env->content))[j] != '\0' && s[j] != '\0'
				&& ((char *)(env->content))[j] != '=')
		{
			if (((char *)(env->content))[j] != s[j])
				break ;
			++j;
		}
		if (s[j] == '\0' && ((char *)env->content)[j] == '=')
		{
			len = ft_strlen(env->content);
			return (ft_substr(env->content, j + 1, len - j - 1));
		}
		env = env->next;
	}
	return (ft_strdup(""));
}
