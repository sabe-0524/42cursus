/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:31:54 by sabe              #+#    #+#             */
/*   Updated: 2025/04/24 22:18:53 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo, t_fork *left_fork, t_fork *right_fork,
		t_table *table)
{
	if (philo->is_even)
	{
		if (get_finish(philo))
			return ;
		pthread_mutex_lock(&left_fork->mutex);
		philo_print(philo, FORK);
		if (get_finish(philo))
		{
			pthread_mutex_unlock(&left_fork->mutex);
			return ;
		}
		pthread_mutex_lock(&right_fork->mutex);
		philo_print(philo, FORK);
	}
	else
	{
		if (get_finish(philo))
			return ;
		pthread_mutex_lock(&right_fork->mutex);
		philo_print(philo, FORK);
		if (get_finish(philo))
		{
			pthread_mutex_unlock(&right_fork->mutex);
			return ;
		}
		pthread_mutex_lock(&left_fork->mutex);
		philo_print(philo, FORK);
	}
	if (get_finish(philo))
	{
		pthread_mutex_unlock(&left_fork->mutex);
		pthread_mutex_unlock(&right_fork->mutex);
		return ;
	}
	update_last_eat(philo);
	philo_print(philo, EAT);
	usleep(table->time_to_eat * 1000);
	add_eat_count(philo);
	pthread_mutex_unlock(&left_fork->mutex);
	pthread_mutex_unlock(&right_fork->mutex);
}

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEP);
	usleep(philo->table->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
}

void	*do_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_finish(philo))
			return (NULL);
		philo_eat(philo, philo->left_fork, philo->right_fork, philo->table);
		if (get_finish(philo))
			return (NULL);
		philo_sleep(philo);
		if (get_finish(philo))
			return (NULL);
		philo_think(philo);
	}
	return (NULL);
}

void	simulate(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_create(&table->philos[i].pthread, NULL, do_philo,
			&table->philos[i]);
		i++;
	}
	pthread_create(&table->finish_pthread, NULL, check_finish, table);
	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->philos[i].pthread, NULL);
		i++;
	}
	pthread_join(table->finish_pthread, NULL);
}
