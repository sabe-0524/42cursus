/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:47:35 by sabe              #+#    #+#             */
/*   Updated: 2025/04/25 22:28:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_fork(t_philo *philo, t_fork *first_fork, t_fork *second_fork)
{
	if (get_finish(philo))
		return (1);
	pthread_mutex_lock(&first_fork->mutex);
	philo_print(philo, FORK);
	if (get_finish(philo))
	{
		pthread_mutex_unlock(&first_fork->mutex);
		return (1);
	}
	pthread_mutex_lock(&second_fork->mutex);
	philo_print(philo, FORK);
	return (0);
}
