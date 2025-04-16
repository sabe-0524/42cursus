/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:21:09 by sabe              #+#    #+#             */
/*   Updated: 2025/04/16 18:02:54 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_row(int fd)
{
	int		row;
	char	*line;

	row = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	return (row);
}

int	count_comp(char **nums)
{
	int	count;

	count = 0;
	while (nums[count])
		count++;
	return (count);
}

void	assign_line(t_map *map, char *line, int i, int fd)
{
	char	**nums;
	int		j;
	int		col;

	j = -1;
	nums = ft_split(line, ' ');
	if (!nums)
		cancel_in_line(map, line, fd);
	col = count_comp(nums);
	if (map->col && map->col != col)
	{
		cancel_in_line(map, line, fd);
		all_free_char(nums);
	}
	map->col = col;
	map->points[i] = (t_mappoint *)ft_calloc(col, sizeof(t_mappoint));
	if (!map->points[i])
	{
		all_free_char(nums);
		cancel_in_line(map, line, fd);
	}
	while (nums[++j])
		assign_point(map, i, j, nums);
	all_free_char(nums);
}

int	open_file(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		cancel_fdf(map);
	return (fd);
}

void	make_map(char **argv, t_map *map)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open_file(argv[1], map);
	map->row = count_row(fd);
	close(fd);
	if (!map->row)
		cancel_fdf(map);
	map->points = (t_mappoint **)ft_calloc(map->row, sizeof(t_mappoint *));
	if (!map->points)
		exit(EXIT_FAILURE);
	i = 0;
	fd = open_file(argv[1], map);
	while (i < map->row)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			cancel_fdf(map);
		assign_line(map, tmp, i, fd);
		free(tmp);
		i++;
	}
	close(fd);
	assign_color_map(map);
}
