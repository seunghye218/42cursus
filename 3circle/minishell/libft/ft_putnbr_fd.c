/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:19:56 by seungpar          #+#    #+#             */
/*   Updated: 2021/12/05 18:41:39 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sub_putnbr_fd(long l, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	l = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	ft_sub_putnbr_fd(l, fd);
}

static void	ft_sub_putnbr_fd(long l, int fd)
{
	if (l == 0)
		return ;
	ft_sub_putnbr_fd(l / 10, fd);
	ft_putchar_fd(l % 10 + '0', fd);
}
