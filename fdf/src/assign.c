/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:18:47 by sabe              #+#    #+#             */
/*   Updated: 2025/04/13 17:34:45 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_index(char *base, char c)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atox(char *str)
{
	int		answer;
	char	*base;

	base = "0123456789abcdef";
	answer = 16 * find_index(base, str[0]) + find_index(base, str[1]);
	return (answer);
}

void	extract_color(int *rgb, char *data)
{
	char	str[2];
	int		i;

	i = 0;
	while (i < 3)
	{
		str[0] = data[2 + 2 * i];
		str[1] = data[3 + 2 * i];
		rgb[i] = ft_atox(str);
		i++;
	}
}

void	assign_point(t_map *map, int i, int j, char *str)
{
	char	**data;
	int		rgb[3];

	map->points[i][j].x = j;
	map->points[i][j].y = i;
	data = ft_split(str, ',');
	if (!data)
	{
		perror(NULL); // TODO error
	}
	map->points[i][j].z = ft_atoi(data[0]);
	if (data[1])
	{
		extract_color(rgb, data[1]);
		map->points[i][j].color.r = rgb[0] * 100;
		map->points[i][j].color.g = rgb[1] * 100;
		map->points[i][j].color.b = rgb[2] * 100;
		map->points[i][j].color_flag = 1;
	}
	else
		map->points[i][j].color_flag = 0;
	all_free_char(data);
}

