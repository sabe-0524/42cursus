/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:04:57 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/17 20:06:19 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	stack->top = stack->top->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	stack->top = stack->top->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = stack_a->top->prev;
	stack_b->top = stack_b->top->prev;
	write(1, "rrr\n", 4);
}
