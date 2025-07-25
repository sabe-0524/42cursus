/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:18:08 by sabe              #+#    #+#             */
/*   Updated: 2025/07/20 13:34:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	init_semaphore();
	if (argc != 5 && argc != 6)
	{
		printf("Invalid argument\n");
		return (1);
	}
	table = init_table(argc, argv);
	simulate(table);
	stop_table(table);
	return (0);
}
