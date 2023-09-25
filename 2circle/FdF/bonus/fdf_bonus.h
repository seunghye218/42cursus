/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:08:29 by seunghye          #+#    #+#             */
/*   Updated: 2022/06/01 12:08:37 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"

typedef struct s_isomap
{
	double	x;
	double	y;
	double	z;
}	t_isomap;

typedef struct s_mapinfo
{
	int	x_max;
	int	x_min;
	int	y_max;
	int	y_min;
	int	x_move;
	int	y_move;
	int	x_len;
	int	y_len;
}	t_mapinfo;

typedef struct s_angle
{
	double	a;
	double	b;
	double	r;
}	t_angle;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			x_size;
	int			y_size;
	int			**altitude;
	int			**color;
	double		winsize;
	double		altsize;
	t_isomap	**isomap;
	t_mapinfo	info;
	t_angle		angle;
	int			iso_on;
}	t_map;

typedef struct s_cd
{
	double	z;
	double	z0;
	double	z1;
	double	dz;
}	t_cd;

size_t		ft_strlen(const char *str);
char		*ft_strchr(char *str, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
void		free_split(char **strs);
int			ft_atoi(const char *str);
int			ft_htoi(char *str);
void		ft_exit(char *str);
void		write_exit(char *str);
int			parsing(char **av, t_map *map);
void		plotline(t_img *data, t_cd xcd, t_cd ycd, int color);
void		init_map(t_map *map);
void		get_info(t_map *map, int x, int y);
t_isomap	**get_isomap(t_map *map, int x, int y);
double		get_winsize(t_map map);
double		get_altsize(t_map map);
void		dda_line(t_img *const data, t_cd xcd, t_cd ycd, int color);
void		draw_fdf(t_map *const map, t_img img);
t_isomap	euler_angle_rotation(int x, int y, int z, t_angle ag);
t_isomap	fixed_angle_rotation(double x, double y, double z, t_angle ag);
t_isomap	x_rotation(int x, int y, int z, double angle);
t_isomap	y_rotation(int x, int y, int z, double angle);
t_isomap	z_rotation(int x, int y, int z, double angle);
t_isomap	**rotation_trans(t_map *map);
void		rotation_hook(int keycode, t_map *map);
void		new_img(t_map	*map);
int			key_hooking(int keycode, t_map *map);
void		mouse_new_img(t_map *map);
int			mouse_hooking(int keycode, int x, int y, t_map *map);

# define BUFFER_SIZE 8192
# define PI 3.14159265

#endif