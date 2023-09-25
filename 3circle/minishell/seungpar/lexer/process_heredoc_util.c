/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:36:20 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/06 21:51:15 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	replace_heredoc_end_to_filename(t_info *info, int n)
{
	char	*filename;
	char	*number;
	t_token	*cur;

	number = ft_itoa(n);
	filename = ft_strjoin("/tmp/seungparseunghye", number);
	free(number);
	cur = get_n_th_heredoc(info, n);
	cur = cur->next;
	free(cur->content);
	cur->content = filename;
}
