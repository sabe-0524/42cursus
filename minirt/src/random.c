/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:57:59 by abesouichir       #+#    #+#             */
/*   Updated: 2025/08/19 21:47:42 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define PM_A 16807
#define PM_M 2147483647
#define PM_Q 127773
#define PM_R 2836

int32_t rand_seed(void)
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  if ((tv.tv_sec * 1000 + tv.tv_usec / 1000) / PM_M != 0)
    return (int32_t)((tv.tv_sec * 1000 + tv.tv_usec / 1000) / PM_M);
  return 1;
}

int32_t rand_int(void)
{
  int32_t seed = rand_seed();
  int32_t hi = seed / PM_Q;
  int32_t lo = seed % PM_Q;
  int32_t test = PM_A * lo - PM_R * hi;
  if (test > 0)
    return test % PM_M;
  return test + PM_M;
}

double rand_double(double min, double max)
{
  return min + (max - min) * ((double)rand_int() / (double)PM_M);
}