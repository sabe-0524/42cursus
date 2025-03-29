/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:14:19 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/29 17:30:14 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_sorted(t_stack *stack)
{
	t_node	*node;
	int		is_first;

	node = stack->top;
	is_first = 1;
	if (!node)
		return (1);
	while (is_first || node->next != stack->top)
	{
		is_first = 0;
		if (node->content > node->next->content || node->next == node)
			return (0);
		node = node->next;
	}
	return (1);
}
