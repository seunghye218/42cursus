/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:21:55 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:50:04 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_img *const data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	dda_line(t_img *const data, t_cd xcd, t_cd ycd, int color)
{
	double	step;
	int		i;

	if (fabs(xcd.dz) >= fabs(ycd.dz))
		step = fabs(xcd.dz);
	else
		step = fabs(ycd.dz);
	xcd.dz /= step;
	ycd.dz /= step;
	i = 0;
	while (i <= step)
	{
		my_mlx_pixel_put(data, (int)xcd.z, (int)ycd.z, color);
		xcd.z += xcd.dz;
		ycd.z += ycd.dz;
		i++;
	}
}
