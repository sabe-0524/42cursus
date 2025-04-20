/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:27:57 by sabe              #+#    #+#             */
/*   Updated: 2025/04/20 18:06:52 by sabe             ###   ########.fr       */
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
	pthread_mutex_lock(&philo->print_mutex);
	printf("%ld %d %s\n", get_time_stamp(philo->table->start_time), philo->id, message);
	pthread_mutex_unlock(&philo->print_mutex);
}

void add_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->meal_mutex);
}
