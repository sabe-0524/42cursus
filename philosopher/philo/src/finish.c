/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:11:07 by sabe              #+#    #+#             */
/*   Updated: 2025/04/25 19:44:35 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_died(t_philo *philo)
{
	long int	starve_time;

	pthread_mutex_lock(&philo->last_time_mutex);
	starve_time = get_time_stamp(philo->table->start_time) - philo->last_eat;
	pthread_mutex_unlock(&philo->last_time_mutex);
	if (starve_time > philo->table->time_to_die)
	{
		philo_print(philo, DIED);
		pthread_mutex_lock(&philo->table->finish_mutex);
		philo->table->finish = 1;
		pthread_mutex_unlock(&philo->table->finish_mutex);
		return (1);
	}
	return (0);
}

int	check_eat(t_philo *philo)
{
	int	times_eat;

	pthread_mutex_lock(&philo->meal_mutex);
	times_eat = philo->times_eat;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (times_eat < philo->table->must_times_eat)
		return (1);
	else
		return (0);
}

void	*check_finish(void *arg)
{
	int		i;
	int		eat_flag;
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		eat_flag = 1;
		while (++i < table->num_philo)
		{
			if (check_died(&table->philos[i]))
				return (NULL);
			if (table->must_times_eat == 0 || check_eat(&table->philos[i]))
				eat_flag = 0;
		}
		if (eat_flag)
		{
			pthread_mutex_lock(&table->finish_mutex);
			table->finish = 1;
			pthread_mutex_unlock(&table->finish_mutex);
			return (NULL);
		}
	}
	return (NULL);
}
