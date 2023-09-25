/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:35:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/12 18:23:47 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_s(va_list ap)
{
	char	*s;
	size_t	len;

	s = va_arg(ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_di(va_list ap)
{
	int		di;
	char	*str;
	size_t	len;

	di = va_arg(ap, int);
	str = ft_itoa(di);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_p(va_list ap)
{
	void	*p;
	char	*str;
	size_t	len;

	p = va_arg(ap, void *);
	str = ft_ptoa(p);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_u(va_list ap)
{
	unsigned int	u;
	char			*str;
	size_t			len;

	u = va_arg(ap, unsigned);
	str = ft_utoa_base(u, 10, 'u');
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
