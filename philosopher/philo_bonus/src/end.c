/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:13:10 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 23:16:44 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_end(t_philo *philo)
{
	long int	starve_time;

	starve_time = get_time_stamp(philo->table->start_time) - philo->last_eat;
	if (starve_time > philo->table->time_to_die)
	{
		sem_wait(philo->table->sem_death);
		philo_print(philo, DIED);
		exit(EXIT_SUCCESS);
	}
}
