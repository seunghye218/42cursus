/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:50:11 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_handle(int keycode, t_map *map)
{
	if (keycode == 5 && map->winsize > 1)
	{
		map->winsize *= 0.8;
		new_img(map);
	}
	if (keycode == 4 && (map->x_size + map->y_size) * map->winsize < 5000)
	{
		map->winsize *= 1.2;
		new_img(map);
	}
}

int	mouse_hooking(int keycode, int x, int y, t_map *map)
{
	if (1 || x || y)
		;
	if (keycode == 5 || keycode == 4)
		zoom_handle(keycode, map);
	return (0);
}
