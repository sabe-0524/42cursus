/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:54:46 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/17 20:06:31 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_three(t_stack *stack)
{
	int	stack_len;

	stack_len = count_stack(stack);
	if (stack_len == 1)
		return ;
	else if (stack_len == 2)
	{
		if (stack->top->content > stack->top->next->content)
			sa(stack);
		return ;
	}
	else if (stack_len == 3)
	{
		if (stack->top->content > stack->top->next->content
			&& stack->top->content > stack->top->prev->content)
			ra(stack);
		else if (stack->top->content < stack->top->next->content
			&& stack->top->prev->content < stack->top->next->content)
			rra(stack);
		if (stack->top->content > stack->top->next->content)
			sa(stack);
	}
}

t_node	*select_best_node(t_stack *stack)
{
	t_node	*node;
	t_node	*best_node;
	int		is_first;

	node = stack->top;
	best_node = stack->top;
	is_first = 1;
	while (is_first || node != stack->top)
	{
		is_first = 0;
		if (best_node->command.all > node->command.all)
			best_node = node;
		node = node->next;
	}
	return (best_node);
}

void	execute_command(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	while (node->command.ra--)
		ra(stack_a);
	while (node->command.rb--)
		rb(stack_b);
	while (node->command.rr--)
		rr(stack_a, stack_b);
	while (node->command.rra--)
		rra(stack_a);
	while (node->command.rrb--)
		rrb(stack_b);
	while (node->command.rrr--)
		rrr(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	rotate_max(t_stack *stack)
{
	t_node	*max_node;
	t_node	*node;
	int		rb_count;
	int		rrb_count;

	max_node = get_max_node(stack);
	node = stack->top;
	rb_count = 0;
	while (node != max_node)
	{
		node = node->next;
		rb_count++;
	}
	rrb_count = count_stack(stack) - rb_count;
	if (rb_count <= rrb_count)
	{
		while (rb_count-- > 0)
			rb(stack);
	}
	else
	{
		while (rrb_count-- > 0)
			rrb(stack);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (count_stack(stack_a) <= 3)
	{
		sort_under_three(stack_a);
		return ;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->top)
	{
		count_r(stack_a, stack_b);
		execute_command(select_best_node(stack_a), stack_a, stack_b);
	}
	rotate_max(stack_b);
	while (stack_b->top)
		pa(stack_a, stack_b);
}
