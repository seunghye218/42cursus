/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:26:21 by seungpar          #+#    #+#             */
/*   Updated: 2022/09/06 21:48:59 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*print_error_and_return(char *msg, int fd, void *ret)
{
	ft_putendl_fd(msg, fd);
	return (ret);
}

int	print_error_and_return_int(char *msg, int fd, int ret)
{
	ft_putendl_fd(msg, fd);
	return (ret);
}

void	print_error_and_exit(char *msg, int fd, int ret)
{
	ft_putendl_fd(msg, fd);
	exit(ret);
}
