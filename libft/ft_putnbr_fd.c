/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:24:58 by seunghye          #+#    #+#             */
/*   Updated: 2021/12/20 18:11:55 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long long nb, long long div, int fd)
{
	char	digit;

	if (!nb)
		write(fd, &"0", 1);
	if (!(nb / div))
		return ;
	ft_putnbr(nb, div * 10, fd);
	digit = nb / div - nb / (div * 10) * 10 + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	if (fd < 0)
		return ;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, &"-", 1);
	}
	ft_putnbr(nb, 1, fd);
}
