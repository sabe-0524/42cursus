/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:47:38 by sabe              #+#    #+#             */
/*   Updated: 2025/04/25 19:41:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	stop_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&table->forks[i].mutex);
		i++;
	}
	free(table->forks);
}

void	stop_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&table->philos[i].last_time_mutex);
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
		i++;
	}
	free(table->philos);
}

void	stop_table(t_table *table)
{
	if (table->forks)
		stop_fork(table);
	if (table->philos)
		stop_philo(table);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->finish_mutex);
	free(table);
}
