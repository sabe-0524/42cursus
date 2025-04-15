/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:41 by sabe              #+#    #+#             */
/*   Updated: 2025/04/15 18:21:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_bresenham	init_br(t_mappoint point_1, t_mappoint point_2)
{
	t_bresenham	br;

	br.start[0] = point_1.screen_x;
	br.start[1] = point_1.screen_y;
	br.dx = abs(point_1.screen_x - point_2.screen_x);
	br.dy = abs(point_1.screen_y - point_2.screen_y);
	if (point_1.screen_x < point_2.screen_x)
		br.sx = 1;
	else
		br.sx = -1;
	if (point_1.screen_y < point_2.screen_y)
		br.sy = 1;
	else
		br.sy = -1;
	br.err = br.dx - br.dy;
	br.color = point_1.color;
	return (br);
}

void	bresenham(t_mappoint point_1, t_mappoint point_2, t_img *img)
{
	t_bresenham	br;

	br = init_br(point_1, point_2);
	br.color = point_1.color;
	while (1)
	{
		my_mlx_pixel_put(img, point_1.screen_x, point_1.screen_y,
			assign_color_pixel(point_1));
		if (point_1.screen_x == point_2.screen_x
			&& point_1.screen_y == point_2.screen_y)
			break ;
		br.err2 = 2 * br.err;
		if (br.err2 > -1 * br.dy)
		{
			br.err -= br.dy;
			point_1.screen_x += br.sx;
			point_1.color = step_color(point_1, point_2, br.start, br.color);
		}
		if (br.err2 < br.dx)
		{
			br.err += br.dx;
			point_1.screen_y += br.sy;
			point_1.color = step_color(point_1, point_2, br.start, br.color);
		}
	}
}

void	round_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->points[i][j].screen_x = round(map->points[i][j].vx);
			map->points[i][j].screen_y = round(map->points[i][j].vy);
			j++;
		}
		i++;
	}
}

void	draw_line(t_img *img, t_map *map)
{
	int	i;
	int	j;

	round_map(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (j < map->col - 1)
				bresenham(map->points[i][j], map->points[i][j + 1], img);
			if (i < map->row - 1)
				bresenham(map->points[i][j], map->points[i + 1][j], img);
			j++;
		}
		i++;
	}
}
