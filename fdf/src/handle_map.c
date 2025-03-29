/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:21:09 by sabe              #+#    #+#             */
/*   Updated: 2025/03/29 21:46:01 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int count_row(int fd)
{
	int row;

	row = 0;
	while(get_next_line(fd))
		row++;
	return (row);
}

t_mappoint **make_map(char **argv)
{
	t_mappoint **map;
	int fd;

	fd = open(argv[1], O_RDONLY);
	map = (t_mappoint **)malloc(sizeof(t_mappoint *) * (count_row(fd) + 1));
	
}
