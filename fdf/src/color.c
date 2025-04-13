/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:31:41 by sabe              #+#    #+#             */
/*   Updated: 2025/04/13 17:31:34 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	assign_color_map(t_map *map)
{
	int		i;
	int		j;
	double	t;

	find_height(map);
	i = -1;
	while (++i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (!map->points[i][j].color_flag)
			{
				t = (map->points[i][j].z - map->min_z) / (map->max_z
						- map->min_z);
				map->points[i][j].color.r = map->low_color.r
					+ (map->high_color.r - map->low_color.r) * t;
				map->points[i][j].color.g = map->low_color.g
					+ (map->high_color.g - map->low_color.g) * t;
				map->points[i][j].color.b = map->low_color.b
					+ (map->high_color.b - map->low_color.b) * t;
			}
			j++;
		}
	}
}

uint32_t	assign_color_pixel(t_mappoint point)
{
	return (0xFF << 24) | ((point.color.r / 100 & 0xFF) << 16) | ((point.color.g
			/ 100 & 0xFF) << 8) | (point.color.b / 100 & 0xFF);
}

t_color	step_color(t_mappoint point_1, t_mappoint point_2, int *start,
		t_color start_color)
{
	t_color	pixel_color_step;
	int		steps;

	steps = abs(point_2.screen_x - start[0]) + abs(point_2.screen_y - start[1]);
	pixel_color_step.r = point_1.color.r + (point_2.color.r - start_color.r)
		/ steps;
	pixel_color_step.g = point_1.color.g + (point_2.color.g - start_color.g)
		/ steps;
	pixel_color_step.b = point_1.color.b + (point_2.color.b - start_color.b)
		/ steps;
	return (pixel_color_step);
}
