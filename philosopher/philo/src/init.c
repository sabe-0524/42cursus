/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:27:27 by sabe              #+#    #+#             */
/*   Updated: 2025/04/16 22:50:42 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_table(t_table *table, int argc, char **argv)
{
	memset(table, 0, sizeof(t_table));
	table->num_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_times_eat = ft_atoi(argv[5]);
}

int	init_table(t_table *table, int argc, char **argv)
{
	assign_table(table, argc, argv);
	if (table->num_philo == 0 || table->time_to_die == 0
		|| table->time_to_eat == 0 || table->time_to_sleep == 0 || (argc == 6
			&& table->must_times_eat == 0))
	{
		printf("Invalid argument\n");
		return (1);
	}
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->num_philo);
	if (!table->philos)
	{
		free(table);
		return (1);
	}
	table->forks = (t_fork *)malloc(sizeof(t_fork) * table->num_philo);
	if (!table->forks)
	{
		free(table->philos);
		free(table);
		return (1);
	}
	return (0);
}

void init_philo(t_table *table)
{
	int i;

	i = 0;
	while (i < table->num_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].is_even = !(i % 2);
		i++;
	}
}

void init_fork(t_table *table)
{
	int i;

	i = 0;
	while (i < table->num_philo)
	{
		table->forks[i].id = i + 1;
		pthread_mutex_init(&table->forks[i].mutex, NULL);
		i++;
	}
}
