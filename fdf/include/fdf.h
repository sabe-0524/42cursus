/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:12 by sabe              #+#    #+#             */
/*   Updated: 2025/04/10 16:51:47 by sabe             ###   ########.fr       */
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
	uint32_t	color;
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

void			make_map(char **argv, t_map *map);
void			all_free_char(char **strs);
void			rotate_map(t_map *map);
void			move_map(t_map *map, int width, int height);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			draw_line(t_img *img, t_map *map);

#endif
