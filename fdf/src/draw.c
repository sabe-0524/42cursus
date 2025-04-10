/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:41 by sabe              #+#    #+#             */
/*   Updated: 2025/04/10 16:52:50 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_mappoint point_1, t_mappoint point_2, t_img *img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err[2];

	dx = abs(point_1.screen_x - point_2.screen_x);
	dy = abs(point_1.screen_y - point_2.screen_y);
	if (point_1.screen_x < point_2.screen_x)
		sx = 1;
	else
		sx = -1;
	if (point_1.screen_y < point_2.screen_y)
		sy = 1;
	else
		sy = -1;
	err[0] = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(img, point_1.screen_x, point_1.screen_y, 0x00ffffff);
		if (point_1.screen_x == point_2.screen_x
			&& point_1.screen_y == point_2.screen_y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] > -1 * dy)
		{
			err[0] -= dy;
			point_1.screen_x += sx;
		}
		if (err[1] < dx)
		{
			err[0] += dx;
			point_1.screen_y += sy;
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
