/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:19 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/12 18:16:49 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(va_list ap, char format)
{
	unsigned int	x;
	char			*str;
	size_t			len;

	x = va_arg(ap, unsigned);
	str = ft_utoa_base(x, 16, format);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_handle(va_list ap, char format)
{
	if (format == 'c')
		return (ft_c(ap));
	else if (format == 's')
		return (ft_s(ap));
	else if (format == 'p')
		return (ft_p(ap));
	else if (format == 'd' || format == 'i')
		return (ft_di(ap));
	else if (format == 'u')
		return (ft_u(ap));
	else if (format == 'x' || format == 'X')
		return (ft_x(ap, format));
	else if (format == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		while (*str && *str != '%' && ++len)
			write(1, str++, 1);
		if (*str && *str++ == '%')
			len += ft_handle(ap, *str++);
	}
	va_end(ap);
	if (len > 2147484647)
		return (-1);
	return (len);
}
