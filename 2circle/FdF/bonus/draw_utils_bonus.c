/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:16:51 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:08:19 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_cd	get_cd(const double z0, const double z1)
{
	t_cd	zcd;

	zcd.z = z0;
	zcd.z0 = z0;
	zcd.z1 = z1;
	zcd.dz = z1 - z0;
	return (zcd);
}

static void	draw_vertical(t_map *const map, int x, int y)
{
	dda_line(&map->img, get_cd(map->isomap[y][x].x - map->info.x_min, \
								map->isomap[y + 1][x].x - map->info.x_min), \
								get_cd(map->isomap[y][x].y - map->info.y_min, \
								map->isomap[y + 1][x].y - map->info.y_min), \
								map->color[y + 1][x]);
}

static void	draw_horizon(t_map *const map, int x, int y)
{
	dda_line(&map->img, get_cd(map->isomap[y][x].x - map->info.x_min, \
						map->isomap[y][x + 1].x - map->info.x_min), \
						get_cd(map->isomap[y][x].y - map->info.y_min, \
						map->isomap[y][x + 1].y - map->info.y_min), \
						map->color[y][x + 1]);
}

void	draw_fdf(t_map *const map, t_img img)
{
	int	y;
	int	x;

	y = 0;
	while (y + 1 < map->y_size)
	{
		x = 0;
		while (x + 1 < map->x_size)
		{
			draw_horizon(map, x, y);
			draw_vertical(map, x, y);
			x++;
		}
		draw_vertical(map, x, y);
		y++;
	}
	x = 0;
	while (x + 1 < map->x_size)
		draw_horizon(map, x++, y);
	mlx_put_image_to_window(map->mlx, map->win, img.img, map->info.x_len / 2 \
					+ map->info.x_move, map->info.y_len / 2 + map->info.y_move);
}

void	new_img(t_map *map)
{
	int			y;
	t_img		img;

	y = 0;
	while (y < map->y_size)
		free(map->isomap[y++]);
	free(map->isomap);
	map->isomap = get_isomap(map, 0, 0);
	get_info(map, 0, 0);
	img.img = mlx_new_image(map->mlx, map->info.x_len, map->info.y_len);
	if (!img.img)
		ft_exit("mlx_new_image error : ");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	mlx_destroy_image (map->mlx, map->img.img);
	mlx_clear_window(map->mlx, map->win);
	map->img = img;
	draw_fdf(map, img);
}
