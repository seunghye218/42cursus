/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:17:14 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:49:35 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	write_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
