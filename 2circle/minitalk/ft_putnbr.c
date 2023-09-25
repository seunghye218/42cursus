/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:24:58 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/27 19:30:57 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int div)
{
	char	digit;

	if (!((n / div) / 10))
	{
		digit = n / div + '0';
		write(1, &digit, 1);
		return ;
	}
	ft_putnbr(n, div * 10);
	digit = (n / div) % 10 + '0';
	write(1, &digit, 1);
}
