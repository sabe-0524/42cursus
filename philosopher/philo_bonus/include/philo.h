/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:16:34 by sabe              #+#    #+#             */
/*   Updated: 2025/07/07 23:16:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_table
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_times_eat;
	long long int	start_time;
	bool			death_flag;
	sem_t			*sem_fork;
	sem_t			*sem_waiter;
	sem_t			*sem_print;
	sem_t			*sem_count;
	sem_t			*sem_control;
	sem_t			*sem_death;
	pid_t			*pids;
	pid_t			death_pid;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				times_eat;
	long int		last_eat;
	t_table			*table;
}					t_philo;

void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);
int					ft_atoi(const char *str);
t_table				*init_table(int argc, char **argv);
t_philo				*init_philo(int i, t_table *table);
void				simulate(t_table *table);
void				my_sem_wait(sem_t *sem);
long int			get_time_stamp(long int start_time);
void				philo_print(t_philo *philo, char *message);
void				stop_table(t_table *table);
void				check_end(t_philo *philo);
void				init_semaphore(void);
void				finish_process(t_table *table);

#endif
