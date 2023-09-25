/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:44:52 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/27 20:05:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_char
{
	char			c;
	unsigned char	i;
}	t_char;

int		ft_atoi(const char *str);
void	ft_putnbr(int n, int div);

#endif