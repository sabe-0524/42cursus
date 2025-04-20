/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:21:55 by sabe              #+#    #+#             */
/*   Updated: 2025/04/20 17:35:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
		return (1);
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (init_table(table, argc, argv))
		return (1);
	init_fork(table);
	init_philo(table);
	simulate(table);
	return (0);
}
