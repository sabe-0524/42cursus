/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:41 by sabe              #+#    #+#             */
/*   Updated: 2025/04/15 17:50:06 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_mappoint point_1, t_mappoint point_2, t_img *img)
{
	int		d[2];
	int		s[2];
	int		err[2];
	int		start[2];
	t_color	start_color;

	start[0] = point_1.screen_x;
	start[1] = point_1.screen_y;
	start_color = point_1.color;
	d[0] = abs(point_1.screen_x - point_2.screen_x);
	d[1] = abs(point_1.screen_y - point_2.screen_y);
	if (point_1.screen_x < point_2.screen_x)
		s[0] = 1;
	else
		s[0] = -1;
	if (point_1.screen_y < point_2.screen_y)
		s[1] = 1;
	else
		s[1] = -1;
	err[0] = d[0] - d[1];
	while (1)
	{
		my_mlx_pixel_put(img, point_1.screen_x, point_1.screen_y,
			assign_color_pixel(point_1));
		if (point_1.screen_x == point_2.screen_x
			&& point_1.screen_y == point_2.screen_y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] > -1 * d[1])
		{
			err[0] -= d[1];
			point_1.screen_x += s[0];
			point_1.color = step_color(point_1, point_2, start, start_color);
		}
		if (err[1] < d[0])
		{
			err[0] += d[0];
			point_1.screen_y += s[1];
			point_1.color = step_color(point_1, point_2, start, start_color);
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
