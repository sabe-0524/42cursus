/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:11:44 by sabe              #+#    #+#             */
/*   Updated: 2025/04/13 20:35:47 by sabe             ###   ########.fr       */
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
			printf("(%f, %f, %f), ", map->points[i][j].vx, map->points[i][j].vy,
				map->points[i][j].vz);
			j++;
		}
		i++;
		printf("\n");
	}
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		perror(NULL); // TODO error
	map->points = NULL;
	map->row = 0;
	map->col = 0;
	map->high_color.r = 25500;
	map->high_color.g = 0;
	map->high_color.b = 25500;
	map->low_color.r = 0;
	map->low_color.g = 25500;
	map->low_color.b = 25500;
	return (map);
}

int	main(int argc, char **argv)
{
	t_fdf 	fdf;
	t_map	*map;

	if (argc != 2)
		return (1);
	map = init_map();
	make_map(argv, map);
	rotate_map(map);
	move_map(map, 960, 540);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, 960, 540, "fdf");
	fdf.img.img = mlx_new_image(fdf.mlx, 960, 540);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length,
			&fdf.img.endian);
	draw_line(&fdf.img, map);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_key_hook(fdf.mlx_win, key_hook, &fdf);
	mlx_hook(fdf.mlx_win, 17, 0, close_win, &fdf);
	mlx_loop(fdf.mlx);
	mlx_destroy_image(fdf.mlx, fdf.img.img);
	mlx_destroy_window(fdf.mlx, fdf.mlx_win);
	mlx_destroy_display(fdf.mlx);
	free(fdf.mlx);
	// free(fdf.mlx_win);
	all_free_map(map);
	return (0);
}
