/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:36:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/12 18:07:20 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_c(va_list ap);
int	ft_s(va_list ap);
int	ft_di(va_list ap);
int	ft_p(va_list ap);
int	ft_u(va_list ap);
int	ft_x(va_list ap, char format);
int	ft_handle(va_list ap, char format);
int	ft_printf(const char *str, ...);

#endif
