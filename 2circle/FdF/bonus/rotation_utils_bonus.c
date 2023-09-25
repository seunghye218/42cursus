/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:49:56 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:09:06 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_isomap	fixed_angle_rotation(double x, double y, double z, t_angle ag)
{
	t_isomap		isomap;
	const double	r = ag.a;
	const double	b = ag.b;
	const double	a = ag.r;

	isomap.x = x * (cos(a) * cos(b)) + y * (cos(a) * sin(b) * sin(r) \
	- sin(a) * cos(r)) + z * (cos(a) * sin(b) * cos(r) + sin(a) * sin(r));
	isomap.y = x * (sin(a) * cos(b)) + y * (sin(a) * sin(b) * sin(r) \
	+ cos(a) * cos(r)) + z * (sin(a) * sin(b) * cos(r) - cos(a) * sin(r));
	isomap.z = y * cos(b) * sin(r) - x * sin(b) + z * cos(b) * cos(r);
	return (isomap);
}

t_isomap	euler_angle_rotation(int x, int y, int z, t_angle ag)
{
	t_isomap		isomap;
	const double	r = ag.r;
	const double	b = ag.b;
	const double	a = ag.a;

	isomap.x = x * (cos(b) * cos(r)) + y * (sin(a) * sin(b) * cos(r) \
	- cos(a) * sin(r)) + z * (cos(a) * sin(b) * cos(r) + sin(a) * sin(r));
	isomap.y = x * (cos(b) * sin(r)) + y * (sin(a) * sin(b) * sin(r) \
	+ cos(a) * cos(r)) + z * (cos(a) * sin(b) * sin(r) - sin(a) * cos(r));
	isomap.z = y * sin(a) * cos(b) - x * sin(b) + z * cos(a) * cos(b);
	return (isomap);
}
