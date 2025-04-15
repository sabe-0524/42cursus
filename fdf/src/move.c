/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:25:13 by sabe              #+#    #+#             */
/*   Updated: 2025/04/15 17:48:45 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_extrema(t_map *map, t_mappoint point)
{
	if (map->min_x > point.vx)
		map->min_x = point.vx;
	if (map->max_x < point.vx)
		map->max_x = point.vx;
	if (map->min_y > point.vy)
		map->min_y = point.vy;
	if (map->max_y < point.vy)
		map->max_y = point.vy;
}

void	find_extrema(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->min_x = map->points[0][0].vx;
	map->max_x = map->points[0][0].vx;
	map->min_y = map->points[0][0].vy;
	map->max_y = map->points[0][0].vy;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			check_extrema(map, map->points[i][j]);
			j++;
		}
		i++;
	}
}

void	expand_map(t_map *map, double ratio)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->points[i][j].x *= ratio;
			map->points[i][j].y *= ratio;
			map->points[i][j].z *= ratio;
			map->points[i][j].vx *= ratio;
			map->points[i][j].vy *= ratio;
			map->points[i][j].vz *= ratio;
			j++;
		}
		i++;
	}
}

void	translate_map(t_map *map, double dist_x, double dist_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->points[i][j].vx += dist_x;
			map->points[i][j].vy += dist_y;
			j++;
		}
		i++;
	}
}

void	move_map(t_map *map, int width, int height)
{
	find_extrema(map);
	if (width / (map->max_x - map->min_x) < height / (map->max_y - map->min_y))
		expand_map(map, width / (map->max_x - map->min_x));
	else
		expand_map(map, height / (map->max_y - map->min_y));
	find_extrema(map);
	translate_map(map, (width - (map->max_x + map->min_x)) / 2, (height
			- (map->max_y + map->min_y)) / 2);
}
