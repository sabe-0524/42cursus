/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:27:34 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 23:24:58 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_routine(int i, t_table *table)
{
	t_philo	*philo;

	philo = init_philo(i, table);
	while (true)
	{
		philo_eat(philo);
		check_end(philo);
		philo_sleep(philo);
		check_end(philo);
		philo_think(philo);
		check_end(philo);
	}
}

void	simulate(t_table *table)
{
	int				i;
	pid_t			pid;
	struct timeval	tv;

	i = 0;
	gettimeofday(&tv, NULL);
	table->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (i < table->num_philo)
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			philo_routine(i, table);
		table->pids[i] = pid;
		i++;
	}
	finish_process(table);
}
