/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:49:11 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/17 20:06:18 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	stack->top = stack->top->next;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	stack->top = stack->top->next;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = stack_a->top->next;
	stack_b->top = stack_b->top->next;
	write(1, "rr\n", 3);
}
