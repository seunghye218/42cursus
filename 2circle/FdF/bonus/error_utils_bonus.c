/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:17:14 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:08:23 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
