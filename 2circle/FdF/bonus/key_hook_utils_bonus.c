/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:04:38 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:08:50 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotation_handle(int keycode, t_map *map)
{
	double	angle;

	angle = PI / 12;
	if (keycode == 12)
		map->angle.a -= angle;
	if (keycode == 13)
		map->angle.a += angle;
	if (keycode == 0)
		map->angle.b -= angle;
	if (keycode == 1)
		map->angle.b += angle;
	if (keycode == 6)
		map->angle.r -= angle;
	if (keycode == 7)
		map->angle.r += angle;
	new_img(map);
}

void	move_handle(int keycode, t_map *map)
{
	if (keycode == 123)
		map->info.x_move += map->info.x_len * 0.2;
	if (keycode == 124)
		map->info.x_move -= map->info.x_len * 0.2;
	if (keycode == 125)
		map->info.y_move -= map->info.y_len * 0.2;
	if (keycode == 126)
		map->info.y_move += map->info.y_len * 0.2;
	new_img(map);
}

void	iso_handle(int keycode, t_map *map)
{
	if (keycode == 34)
	{
		map->angle.a = 0;
		map->angle.b = 0;
		if (map->iso_on)
		{
			map->iso_on = 0;
			map->angle.r = 0;
		}
		else
		{
			map->iso_on = 1;
			map->angle.r = -PI / 2;
		}
	}
	new_img(map);
}

void	altitude_handle(int keycode, t_map *map)
{
	if (keycode == 27 && map->altsize > 0.01)
		map->altsize *= 0.8;
	if (keycode == 24 && map->altsize < 2.5)
		map->altsize *= 1.2;
	new_img(map);
}

int	key_hooking(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	if (keycode == 49)
	{
		init_map(map);
		new_img(map);
	}
	if (keycode == 12 || keycode == 13 || keycode == 0 || \
		keycode == 1 || keycode == 6 || keycode == 7)
		rotation_handle(keycode, map);
	if (keycode == 24 || keycode == 27)
		altitude_handle(keycode, map);
	if (keycode == 34)
		iso_handle(keycode, map);
	if (keycode >= 123 && keycode <= 126)
		move_handle(keycode, map);
	return (0);
}
