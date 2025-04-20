/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:27:57 by sabe              #+#    #+#             */
/*   Updated: 2025/04/20 20:25:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int get_time_stamp(long int start_time)
{
	struct timeval tv;
	long int time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_stamp - start_time);
}

void philo_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	pthread_mutex_lock(&philo->table->finish_mutex);
	if (!philo->table->finish)
		printf("%ld %d %s\n", get_time_stamp(philo->table->start_time), philo->id, message);
	pthread_mutex_unlock(&philo->table->finish_mutex);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void add_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void update_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_time_mutex);
	philo->last_eat = get_time_stamp(philo->table->start_time);
	pthread_mutex_unlock(&philo->last_time_mutex);
}
