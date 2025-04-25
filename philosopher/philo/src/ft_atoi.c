/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:43:44 by sabe              #+#    #+#             */
/*   Updated: 2025/04/25 19:41:54 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long int	ft_atol(const char *str)
{
	size_t		count;
	long int	answer;

	count = 0;
	answer = 0;
	while (str[count])
	{
		if (!('0' <= str[count] && str[count] <= '9'))
			return (0);
		answer *= 10;
		answer += str[count] - '0';
		count++;
	}
	return (answer);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
