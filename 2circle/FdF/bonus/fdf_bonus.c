/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:54:27 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:08:26 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	my_loop(t_map *map)
{
	mlx_key_hook(map->win, key_hooking, map);
	mlx_mouse_hook(map->win, mouse_hooking, map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		write_exit("Usage : ./fdf <filename> [ case_size z_size ]\n");
	parsing(av, &map);
	map.mlx = mlx_init();
	if (!map.mlx)
		write_exit("mlx_init error\n");
	map.iso_on = 1;
	init_map(&map);
	map.isomap = get_isomap(&map, 0, 0);
	get_info(&map, 0, 0);
	map.win = mlx_new_window(map.mlx, \
							map.info.x_len * 2, map.info.y_len * 2, "fdf");
	if (!map.win)
		write_exit("mlx_new_window error\n");
	map.img.img = mlx_new_image(map.mlx, map.info.x_len, map.info.y_len);
	if (!map.img.img)
		write_exit("mlx_new_image error\n");
	map.img.addr = mlx_get_data_addr(map.img.img, \
	&map.img.bits_per_pixel, &map.img.line_length, &map.img.endian);
	draw_fdf(&map, map.img);
	my_loop(&map);
	return (0);
}

void	init_map(t_map *map)
{
	map->angle.a = 0;
	map->angle.b = 0;
	if (map->iso_on)
		map->angle.r = -PI / 2;
	else
		map->angle.r = 0;
	map->winsize = get_winsize(*map);
	map->altsize = get_altsize(*map);
	map->info.x_move = 0;
	map->info.y_move = 0;
}
