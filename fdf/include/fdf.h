/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:12 by sabe              #+#    #+#             */
/*   Updated: 2025/04/13 18:33:53 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define _USE_MATH_DEFINES
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_mappoint
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	int			screen_x;
	int			screen_y;
	t_color		color;
	int			color_flag;
}				t_mappoint;

typedef struct s_map
{
	t_mappoint	**points;
	int			col;
	int			row;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		max_z;
	double		min_z;
	t_color		high_color;
	t_color		low_color;
}				t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_drawpoint
{
	int			x;
	int			y;
	uint32_t	color;
}				t_drawpoint;

typedef struct s_fdf
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
}				t_fdf;

void			make_map(char **argv, t_map *map);
void			all_free_char(char **strs);
void			rotate_map(t_map *map);
void			move_map(t_map *map, int width, int height);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			draw_line(t_img *img, t_map *map);
void			assign_color_map(t_map *map);
void			find_height(t_map *map);
uint32_t		assign_color_pixel(t_mappoint point);
t_color			step_color(t_mappoint point_1, t_mappoint point_2, int *start,
					t_color start_color);
void			assign_point(t_map *map, int i, int j, char *str);
void			all_free_map(t_map *map);
int				key_hook(int keycode, t_fdf *fdf);

#endif
