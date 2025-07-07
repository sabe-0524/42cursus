/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:53:42 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 19:11:45 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	my_sem_wait(sem_t *sem)
{
	if (sem_wait(sem) == -1)
	{
		exit(EXIT_FAILURE);
	}
}

void	philo_print(t_philo *philo, char *message)
{
	my_sem_wait(philo->table->sem_print);
	printf("%ld %d %s\n", get_time_stamp(philo->table->start_time), philo->id,
		message);
	sem_post(philo->table->sem_print);
}

long int	get_time_stamp(long int start_time)
{
	struct timeval	tv;
	long int		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_stamp - start_time);
}
