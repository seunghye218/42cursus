/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:32:10 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/07 19:34:16 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_strjoin_value(char **splited)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = NULL;
	tmp = NULL;
	while (splited[i] != NULL)
	{
		if (ret == NULL)
			tmp = ft_strjoin("", splited[i++]);
		else
		{
			tmp = ft_strjoin(ret, splited[i++]);
			free(ret);
		}
		ret = tmp;
	}
	return (ret);
}
