/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:33:32 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 23:30:31 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_sem(t_table *table)
{
	table->sem_fork = sem_open("/fork", O_CREAT | O_EXCL, 0644,
			table->num_philo);
	table->sem_waiter = sem_open("/waiter", O_CREAT | O_EXCL, 0644,
			table->num_philo - 1);
	table->sem_print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	table->sem_count = sem_open("/count", O_CREAT | O_EXCL, 0644, 0);
	table->sem_death = sem_open("/death", O_CREAT | O_EXCL, 0644, 1);
	table->sem_control = sem_open("/control", O_CREAT | O_EXCL, 0644, 0);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	memset(table, 0, sizeof(t_table));
	table->num_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->pids = (pid_t *)malloc(sizeof(pid_t) * table->num_philo);
	if (argc == 6)
		table->must_times_eat = ft_atoi(argv[5]);
	init_sem(table);
	if (table->num_philo == 0 || table->time_to_die == 0
		|| table->time_to_eat == 0 || table->time_to_sleep == 0 || (argc == 6
			&& table->must_times_eat == 0))
	{
		printf("Invalid argument\n");
		stop_table(table);
		exit(1);
	}
	return (table);
}

t_philo	*init_philo(int i, t_table *table)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	philo->id = i + 1;
	philo->table = table;
	return (philo);
}

void	init_semaphore(void)
{
	sem_unlink("/count");
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/waiter");
	sem_unlink("/control");
	sem_unlink("/death");
}
