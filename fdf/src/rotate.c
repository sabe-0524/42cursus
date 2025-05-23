/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:22:02 by sabe              #+#    #+#             */
/*   Updated: 2025/04/15 17:48:46 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_point(t_map *map, int i, int j)
{
	map->points[i][j].vx = map->points[i][j].x / sqrt(2) - map->points[i][j].y
		/ sqrt(2);
	map->points[i][j].vy = map->points[i][j].x / sqrt(6) + map->points[i][j].y
		/ sqrt(6) - 2 * map->points[i][j].z / sqrt(6);
	map->points[i][j].vz = -1 * map->points[i][j].x / sqrt(3)
		- map->points[i][j].y / sqrt(3) + map->points[i][j].z / sqrt(3);
}

void	rotate_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			rotate_point(map, i, j);
			j++;
		}
		i++;
	}
}
