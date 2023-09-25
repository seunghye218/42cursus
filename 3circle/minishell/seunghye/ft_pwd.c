/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:10:40 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/09 15:01:24 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_pwd(char **args, t_list **env)
{
	char	*path;

	if (1 || args || env)
		;
	path = getcwd(0, 0);
	if (!path)
		return (1);
	ft_putendl_fd(path, 1);
	free(path);
	return (0);
}
