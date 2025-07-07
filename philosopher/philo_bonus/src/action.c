/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:10:29 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 23:07:19 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_fork(t_philo *philo)
{
	my_sem_wait(philo->table->sem_waiter);
	check_end(philo);
	my_sem_wait(philo->table->sem_fork);
	check_end(philo);
	philo_print(philo, FORK);
	my_sem_wait(philo->table->sem_fork);
	check_end(philo);
	philo_print(philo, FORK);
	sem_post(philo->table->sem_waiter);
}

void	philo_eat(t_philo *philo)
{
	take_fork(philo);
	philo->last_eat = get_time_stamp(philo->table->start_time);
	philo_print(philo, EAT);
	usleep(philo->table->time_to_eat * 1000);
	philo->times_eat++;
	if (philo->times_eat == philo->table->must_times_eat)
		sem_post(philo->table->sem_count);
	sem_post(philo->table->sem_fork);
	sem_post(philo->table->sem_fork);
}

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEP);
	usleep(philo->table->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
	usleep(1000);
}
