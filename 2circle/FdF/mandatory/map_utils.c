/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:51:58 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:28:05 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(t_isomap *new)
{
	const double	cos_a = 0.866025;
	const double	sin_a = 0.5;
	double			pre_x;
	double			pre_y;

	pre_x = new->x;
	pre_y = new->y;
	new->x = (pre_x - pre_y) * cos_a;
	new->y = (pre_x + pre_y) * sin_a - new->z;
}

t_isomap	**get_isomap(t_map *map, int x, int y)
{
	const double	winsize = map->winsize;
	t_isomap		**new;

	new = malloc(sizeof(t_isomap *) * map->y_size);
	if (!new)
		write_exit("get_isomap() malloc error");
	y = 0;
	while (y < map->y_size)
	{
		new[y] = malloc(sizeof(t_isomap) * (map->x_size));
		if (!new[y])
			write_exit("get_isomap() malloc error");
		x = 0;
		while (x < map->x_size)
		{
			new[y][x] = fixed_angle_rotation(x * winsize, y * winsize, \
					map->altitude[y][x] * map->altsize * winsize, map->angle);
			if (map->iso_on)
				iso(&new[y][x]);
			x++;
		}
		y++;
	}
	return (new);
}

void	get_info(t_map *map, int x, int y)
{
	map->info.x_max = 0;
	map->info.x_min = 0;
	map->info.y_max = 0;
	map->info.y_min = 0;
	while (y < map->y_size)
	{
		x = 0;
		while (x < map->x_size)
		{
			if (map->info.x_max < map->isomap[y][x].x)
				map->info.x_max = map->isomap[y][x].x;
			if (map->info.x_min > map->isomap[y][x].x)
				map->info.x_min = map->isomap[y][x].x;
			if (map->info.y_max < map->isomap[y][x].y)
				map->info.y_max = map->isomap[y][x].y;
			if (map->info.y_min > map->isomap[y][x].y)
				map->info.y_min = map->isomap[y][x].y;
			x++;
		}
		y++;
	}
	map->info.x_len = map->info.x_max - map->info.x_min + 1;
	map->info.y_len = map->info.y_max - map->info.y_min + 1;
}

double	get_winsize(t_map map)
{
	double	winsize;

	if (map.x_size + map.y_size <= 50)
		winsize = 30;
	else if (map.x_size + map.y_size <= 100)
		winsize = 15;
	else if (map.x_size + map.y_size <= 200)
		winsize = 5;
	else if (map.x_size + map.y_size <= 400)
		winsize = 3;
	else if (map.x_size + map.y_size <= 800)
		winsize = 3;
	else
		winsize = 1;
	return (winsize);
}

double	get_altsize(t_map map)
{
	double	altsize;
	int		highest;
	int		x;
	int		y;

	highest = map.altitude[0][0];
	y = 0;
	while (y < map.y_size)
	{
		x = 0;
		while (x < map.x_size)
		{
			if (highest < map.altitude[y][x])
				highest = map.altitude[y][x];
			x++;
		}
		y++;
	}
	if (highest > (map.x_size + map.y_size) / 2)
		altsize = 0.3;
	else
		altsize = 1;
	return (altsize);
}
