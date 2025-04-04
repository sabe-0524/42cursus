/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:11:44 by sabe              #+#    #+#             */
/*   Updated: 2025/03/31 22:18:53 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			printf("(%f, %f, %f), ", map->points[i][j].vx, map->points[i][j].vy, map->points[i][j].vz);
			j++;
		}
		i++;
		printf("\n");
	}
}

t_map	*init_map()
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		perror(NULL); //TODO error
	map->points = NULL;
	map->row = 0;
	map->col = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);
	map = init_map();
	make_map(argv, map);
	rotate_map_z(map, -1 * M_PI/ 4);
	return (0);
}
