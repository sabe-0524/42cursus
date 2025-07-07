/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:59:34 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 23:30:51 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	finish_sem(t_table *table)
{
	sem_close(table->sem_count);
	sem_unlink("/count");
	sem_close(table->sem_fork);
	sem_unlink("/fork");
	sem_close(table->sem_print);
	sem_unlink("/print");
	sem_close(table->sem_waiter);
	sem_unlink("/waiter");
	sem_close(table->sem_control);
	sem_unlink("/control");
	sem_close(table->sem_death);
	sem_unlink("/death");
}

void	stop_table(t_table *table)
{
	finish_sem(table);
	free(table->pids);
	free(table);
}

void	*death_thread(void *arg)
{
	t_table	*table;
	int		status;
	pid_t	pid;

	table = (t_table *)arg;
	pid = waitpid(-1, &status, 0);
	if (pid > 0)
	{
		table->death_flag = 1;
		table->death_pid = pid;
		sem_post(table->sem_control);
	}
	return (NULL);
}

void	*count_thread(void *arg)
{
	t_table	*table;
	int		i;

	i = 0;
	table = (t_table *)arg;
	while (i < table->num_philo)
	{
		sem_wait(table->sem_count);
		i++;
	}
	sem_post(table->sem_control);
	return (NULL);
}

void	finish_process(t_table *table)
{
	pthread_t	th1;
	pthread_t	th2;
	int			i;

	pthread_create(&th1, NULL, death_thread, table);
	pthread_detach(th1);
	pthread_create(&th2, NULL, count_thread, table);
	pthread_detach(th2);
	sem_wait(table->sem_control);
	i = 0;
	while (i < table->num_philo)
	{
		if (table->death_flag)
		{
			if (table->pids[i] != table->death_pid)
				kill(table->pids[i], SIGTERM);
		}
		else
			kill(table->pids[i], SIGTERM);
		i++;
	}
	i = 0;
	while (i < table->num_philo)
		waitpid(table->pids[i++], NULL, 0);
}
