/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:14:12 by sabe              #+#    #+#             */
/*   Updated: 2025/04/09 19:28:35 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

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
	uint32_t	color;
}				t_mappoint;

typedef struct s_map
{
	t_mappoint	**points;
	int			col;
	int			row;
}				t_map;

void			make_map(char **argv, t_map *map);
void			all_free_char(char **strs);
void			rotate_map_z(t_map *map);

#endif
