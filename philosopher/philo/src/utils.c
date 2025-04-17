/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:27:57 by sabe              #+#    #+#             */
/*   Updated: 2025/04/17 18:41:36 by sabe             ###   ########.fr       */
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
