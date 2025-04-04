/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:21:09 by sabe              #+#    #+#             */
/*   Updated: 2025/03/31 21:51:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_row(int fd)
{
	int	row;

	row = 0;
	while (get_next_line(fd))
		row++;
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

void	assign_line(t_map *map, char *line, int i)
{
	char	**nums;
	int		j;
	int		col;

	j = 0;
	nums = ft_split(line, ' ');
	if (!nums)
	{
		perror(NULL); // ToDo エラー処理
	}
	col = count_comp(nums);
	map->col = col;
	map->points[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * col);
	if (!map->points[i])
	{
		perror(NULL); // ToDo エラー処理
	}
	while (nums[j])
	{
		map->points[i][j].x = j;
		map->points[i][j].y = map->col - i - 1;
		map->points[i][j].z = ft_atoi(nums[j]);
		j++;
	}
	all_free_char(nums);
}

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	make_map(char **argv, t_map *map)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open_file(argv[1]);
	map->row = count_row(fd);
	close(fd);
	map->points = (t_mappoint **)ft_calloc(map->row, sizeof(t_mappoint *));
	if (!map->points)
		exit(EXIT_FAILURE);
	i = 0;
	fd = open_file(argv[1]);
	while (i < map->row)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			perror(NULL); // TODO error
		}
		assign_line(map, tmp, i);
		free(tmp);
		i++;
	}
	close(fd);
}
