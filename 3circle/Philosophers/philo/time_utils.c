/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:48:34 by seunghye          #+#    #+#             */
/*   Updated: 2022/07/21 11:52:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_ms(void)
{
	struct timeval	s_time;

	if (gettimeofday(&s_time, 0))
		printf("gettimeofday error\n");
	return (s_time.tv_sec * 1000 + s_time.tv_usec / 1000);
}

void	ft_msleep(int time)
{
	while (time >= get_time_ms())
		usleep(512);
}
