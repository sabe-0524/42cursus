/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:10:18 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/01 21:40:14 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack *stack)
{
    t_node *tmp_next;
    t_node *tmp_prev;

    tmp_next = stack->top->next;
    tmp_prev = stack->top->prev;
    stack->top->next = stack->top->next->next;
    stack->top->prev = tmp_next;
    tmp_next->next->prev = stack->top;
    tmp_next->next = stack->top;
    tmp_next->prev = tmp_prev;
    tmp_prev->next = tmp_next;
    stack->top = tmp_next;
}

void sa(t_stack *stack)
{
    swap(stack);
    write(1, "sa\n", 3);
}

void sb(t_stack *stack)
{
    swap(stack);
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}