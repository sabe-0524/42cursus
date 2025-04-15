/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:18:47 by sabe              #+#    #+#             */
/*   Updated: 2025/04/15 17:48:38 by sabe             ###   ########.fr       */
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

uint32_t	ft_atox(char *str)
{
	uint32_t	answer;
	char		*base;
	int			i;

	i = 2;
	base = "0123456789abcdef";
	answer = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		answer = 16 * answer + find_index(base, str[i]);
		i++;
	}
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
	char		**data;
	uint32_t	rgb;

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
		rgb = ft_atox(data[1]);
		map->points[i][j].color.r = ((rgb >> 16) & 0xFF) * 100;
		map->points[i][j].color.g = ((rgb >> 8) & 0xFF) * 100;
		map->points[i][j].color.b = (rgb & 0xff) * 100;
		map->points[i][j].color_flag = 1;
	}
	else
		map->points[i][j].color_flag = 0;
	all_free_char(data);
}
