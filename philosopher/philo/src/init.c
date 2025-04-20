/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:27:27 by sabe              #+#    #+#             */
/*   Updated: 2025/04/20 18:48:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_table(t_table *table, int argc, char **argv)
{
	struct timeval	tv;

	memset(table, 0, sizeof(t_table));
	gettimeofday(&tv, NULL);
	table->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	table->num_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_times_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&table->finish_mutex, NULL);
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

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].is_even = !(i % 2);
		if (i == table->num_philo - 1)
		{
			table->philos[i].right_fork = &table->forks[0];
			table->philos[i].left_fork = &table->forks[i];
		}
		else
		{
			table->philos[i].right_fork = &table->forks[i + 1];
			table->philos[i].left_fork = &table->forks[i];
		}
		table->philos[i].table = table;
		table->philos[i].times_eat = 0;
		pthread_mutex_init(&table->philos[i].print_mutex, NULL);
		pthread_mutex_init(&table->philos[i].meal_mutex, NULL);
		pthread_mutex_init(&table->philos[i].last_time_mutex, NULL);
		i++;
	}
}

void	init_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		table->forks[i].id = i + 1;
		pthread_mutex_init(&table->forks[i].mutex, NULL);
		i++;
	}
}
