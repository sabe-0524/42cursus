/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:22:25 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/23 16:05:57 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max_node(t_stack *stack)
{
	t_node	*node;
	t_node	*max_node;
	int		is_first;

	node = stack->top;
	max_node = stack->top;
	is_first = 1;
	while (is_first || node != stack->top)
	{
		is_first = 0;
		if (max_node->content < node->content)
			max_node = node;
		node = node->next;
	}
	return (max_node);
}

t_node	*get_min_node(t_stack *stack)
{
	t_node	*node;
	t_node	*min_node;
	int		is_first;

	node = stack->top;
	min_node = stack->top;
	is_first = 1;
	while (is_first || node != stack->top)
	{
		is_first = 0;
		if (min_node->content > node->content)
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	target = stack_b->top->content;
	while (!((stack_a->top->content > target
				&& stack_a->top->prev->content < target)
			|| (stack_a->top->content < stack_a->top->prev->content
				&& stack_a->top->content > target)
			|| (stack_a->top->content < stack_a->top->prev->content
				&& stack_a->top->prev->content < target)))
		rra(stack_a);
	pa(stack_a, stack_b);
}

void	rotate_min(t_stack *stack)
{
	t_node	*min_node;
	t_node	*node;
	int		ra_count;
	int		rra_count;

	min_node = get_min_node(stack);
	node = stack->top;
	ra_count = 0;
	while (node != min_node)
	{
		node = node->next;
		ra_count++;
	}
	rra_count = count_stack(stack) - ra_count;
	if (ra_count <= rra_count)
	{
		while (ra_count-- > 0)
			ra(stack);
	}
	else
	{
		while (rra_count-- > 0)
			rra(stack);
	}
}
