/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:22:15 by sabe              #+#    #+#             */
/*   Updated: 2025/04/25 18:54:04 by sabe             ###   ########.fr       */
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

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_fork	t_fork;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	int					is_even;
	int					times_eat;
	long int			last_eat;
	pthread_t			pthread;
	t_fork				*right_fork;
	t_fork				*left_fork;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		last_time_mutex;
	t_table				*table;
}						t_philo;

typedef struct s_fork
{
	int					id;
	pthread_mutex_t		mutex;
}						t_fork;

typedef struct s_table
{
	t_philo				*philos;
	t_fork				*forks;
	pthread_t			finish_pthread;
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_times_eat;
	long int			start_time;
	int					finish;
	pthread_mutex_t		finish_mutex;
	pthread_mutex_t		print_mutex;
}						t_table;

int						init_table(t_table *table, int argc, char **argv);
void					init_philo(t_table *table);
void					init_fork(t_table *table);
long int				get_time_stamp(long int start_time);
int						ft_atoi(const char *str);
void					simulate(t_table *table);
void					philo_print(t_philo *philo, char *message);
void					add_eat_count(t_philo *philo);
void					*check_finish(void *arg);
void					update_last_eat(t_philo *philo);
int						get_finish(t_philo *philo);
void					stop_table(t_table *table);

#endif
