/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:06:59 by sabe              #+#    #+#             */
/*   Updated: 2025/04/13 18:29:31 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	all_free_char(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	find_height(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->max_z = map->points[0][0].z;
	map->min_z = map->points[0][0].z;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->max_z < map->points[i][j].z)
				map->max_z = map->points[i][j].z;
			if (map->min_z > map->points[i][j].z)
				map->min_z = map->points[i][j].z;
			j++;
		}
		i++;
	}
}

void	all_free_points( t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row && map->points[i])
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
}

void	all_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->points)
		all_free_points(map);
	free(map);
}
