/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:31:54 by sabe              #+#    #+#             */
/*   Updated: 2025/04/17 20:23:27 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo, t_fork *left_fork, t_fork *right_fork,
		t_table *table)
{
	if (philo->is_even)
	{
		pthread_mutex_lock(&left_fork->mutex);
		printf("%ld %d has taken a fork\n", get_time_stamp(table->start_time),
			philo->id);
		pthread_mutex_lock(&right_fork->mutex);
		printf("%ld %d has taken a fork\n", get_time_stamp(table->start_time),
			philo->id);
	}
	else
	{
		pthread_mutex_lock(&right_fork->mutex);
		printf("%ld %d has taken a fork\n", get_time_stamp(table->start_time),
			philo->id);
		pthread_mutex_lock(&left_fork->mutex);
		printf("%ld %d has taken a fork\n", get_time_stamp(table->start_time),
			philo->id);
	}
	printf("%ld %d is eating\n", get_time_stamp(table->start_time), philo->id);
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(&left_fork->mutex);
	pthread_mutex_unlock(&right_fork->mutex);
	philo->times_eat++;
}

void	philo_sleep(t_philo *philo, int time_to_sleep, long int start_time)
{
	printf("%ld %d is sleeping\n", get_time_stamp(start_time), philo->id);
	usleep(time_to_sleep * 1000);
}

void	philo_think(t_philo *philo, long int start_time)
{
	printf("%ld %d is thinking\n", get_time_stamp(start_time), philo->id);
}

void	*do_philo(void *arg)
{
	t_var	*var;

	var = (t_var *)arg;
	while (1)
	{
		philo_eat(var->philo, var->left_fork, var->right_fork, var->table);
		philo_sleep(var->philo, var->table->time_to_sleep,
			var->table->start_time);
		philo_think(var->philo, var->table->start_time);
	}
	return (NULL);
}

void	simulate(t_table *table)
{
	int		i;
	t_var	*var;

	i = 0;
	var = (t_var *)malloc(sizeof(t_var) * table->num_philo);
	if (!var)
	{
		return ; // TODO_error
	}
	while (i < table->num_philo)
	{
		var[i].table = table;
		var[i].philo = &table->philos[i];
		var[i].left_fork = &table->forks[i];
		if (i == table->num_philo - 1)
			var[i].right_fork = &table->forks[0];
		else
			var[i].right_fork = &table->forks[i + 1];
		pthread_create(&table->philos[i].pthread, NULL, &do_philo, &var[i]);
		i++;
	}
	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->philos[i].pthread, NULL);
		i++;
	}
}
