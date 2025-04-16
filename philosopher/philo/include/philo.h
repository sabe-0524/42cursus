/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:22:15 by sabe              #+#    #+#             */
/*   Updated: 2025/04/16 23:08:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				is_even;
	int				times_eat;
	pthread_t		pthread;
}					t_philo;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_table
{
	t_philo			*philos;
	t_fork			*forks;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_times_eat;
	long int		start_time;
}					t_table;

int					init_table(t_table *table, int argc, char **argv);
void				init_philo(t_table *table);
void				init_fork(t_table *table);

#endif
