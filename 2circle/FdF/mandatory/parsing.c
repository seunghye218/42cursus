/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:53:53 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 11:50:14 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*read_all(int fd)
{
	char	*all;
	char	*buf;
	ssize_t	n;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		ft_exit("parsing.c malloc() error");
	n = read(fd, buf, BUFFER_SIZE);
	if (n <= 0)
		write_exit("No data found.\n");
	buf[n] = 0;
	all = 0;
	while (n > 0)
	{
		all = ft_strjoin(all, buf);
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			ft_exit("parsing.c malloc() error");
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = 0;
	}
	free(buf);
	return (all);
}

static void	arg_trans(t_map *map, char **args, int i, int x_size)
{
	int		j;
	char	**att_clr;

	j = 0;
	while (j < x_size)
	{
		att_clr = ft_split(args[j], ',');
		map->altitude[i][j] = ft_atoi(att_clr[0]);
		if (att_clr[1])
		{
			map->color[i][j] = ft_htoi(att_clr[1]);
			free_split(att_clr);
		}
		else
		{
			map->color[i][j] = 0x00ffffff;
			free_split(att_clr);
		}
		j++;
	}
}

static void	check_args(char	**args, t_map map)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i < map.x_size)
		write_exit("Found wrong line length. Exiting.\n");
}

static void	map_alloc(char **lines, t_map *map, int x_size, int y_size)
{
	int		i;
	char	**args;

	map->altitude = (int **)malloc(sizeof(int *) * y_size);
	if (!map->altitude)
		ft_exit("parsing.c map_alloc error");
	map->color = malloc(sizeof(int *) * y_size);
	if (!map->color)
		ft_exit("parsing.c map_alloc error");
	i = 0;
	while (i < map->y_size)
	{
		args = ft_split(lines[i], ' ');
		check_args(args, *map);
		map->altitude[i] = malloc(sizeof(int) * x_size);
		if (!map->altitude[i])
			ft_exit("parsing.c map_alloc error");
		map->color[i] = malloc(sizeof(int) * x_size);
		if (!map->color[i])
			ft_exit("parsing.c map_alloc error");
		arg_trans(map, args, i, x_size);
		free_split(args);
		i++;
	}
}

int	parsing(char **av, t_map *map)
{
	ssize_t	fd;
	char	**lines;
	char	*map_data;
	char	**args;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit("parsing.c open() error");
	map_data = read_all(fd);
	lines = ft_split(map_data, '\n');
	free(map_data);
	map->y_size = 0;
	while (lines[map->y_size])
		map->y_size++;
	args = ft_split(*lines, ' ');
	map->x_size = 0;
	while (args[map->x_size])
		map->x_size++;
	free_split(args);
	map_alloc(lines, map, map->x_size, map->y_size);
	free_split(lines);
	close(fd);
	return (0);
}
