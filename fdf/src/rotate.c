/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:22:02 by sabe              #+#    #+#             */
/*   Updated: 2025/03/31 21:37:23 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void rotate_point_z(t_map *map, double rad, int i, int j)
{
	map->points[i][j].vx = map->points[i][j].x * cos(rad) - map->points[i][j].y * sin(rad);
	map->points[i][j].vy = map->points[i][j].x * sin(rad) + map->points[i][j].y * cos(rad);
	map->points[i][j].vz = map->points[i][j].z;
}

void rotate_map_z(t_map *map, double rad)
{
	int i;
	int j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			rotate_point_z(map, rad, i, j);
			j++;
		}
		i++;
	}
}
