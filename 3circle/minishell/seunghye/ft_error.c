/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:22:03 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/06 11:24:30 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_perror(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}
