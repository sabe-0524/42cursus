/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:31:41 by sabe              #+#    #+#             */
/*   Updated: 2025/04/12 18:55:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_color	init_color(t_map *map)
{
	t_color	point_color;

	point_color.low_r = map->low_color >> 16 & 0xFF;
	point_color.high_r = map->high_color >> 16 & 0xFF;
	point_color.low_g = map->low_color >> 8 & 0xFF;
	point_color.high_g = map->high_color >> 8 & 0xFF;
	point_color.low_b = map->low_color & 0xFF;
	point_color.high_b = map->high_color & 0xFF;
	return (point_color);
}

void	assign_color_map(t_map *map)
{
	int			i;
	int			j;
	t_color		point_color;
	double		t;
	uint32_t	rgb[3];

	find_height(map);
	i = 0;
	point_color = init_color(map);
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			t = (double)(map->points[i][j].z - map->min_z) / (map->max_z - map->min_z);
			rgb[0] = point_color.low_r + (uint8_t)((point_color.high_r
						- point_color.low_r) * t);
			rgb[1] = point_color.low_g + (uint8_t)((point_color.high_g
						- point_color.low_g) * t);
			rgb[2] = point_color.low_b + (uint8_t)((point_color.high_b
						- point_color.low_b) * t);
			map->points[i][j].color = (0xff << 24) | (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
			j++;
		}
		i++;
	}
}

