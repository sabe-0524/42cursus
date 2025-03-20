/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:52 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/20 17:56:23 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

  if (argc == 1)
      return (0);
	alert_error(argc, argv);
	stack_a = create_stack(argc, argv);
	if (!stack_a)
		exit(1);
	if (check_stack_sorted(stack_a))
	{
		all_free(stack_a);
		return (0);
	}
	stack_b = create_stack(0, NULL);
	if (!stack_b)
	{
		all_free(stack_a);
		exit(1);
	}
	sort(stack_a, stack_b);
	all_free(stack_a);
	all_free(stack_b);
	return (0);
}
