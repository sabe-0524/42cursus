/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:11:44 by sabe              #+#    #+#             */
/*   Updated: 2025/04/10 16:56:10 by sabe             ###   ########.fr       */
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
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	if (argc != 2)
		return (1);
	map = init_map();
	make_map(argv, map);
	rotate_map(map);
	move_map(map, 960, 540);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "Hello world!");
	img.img = mlx_new_image(mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_line(&img, map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
