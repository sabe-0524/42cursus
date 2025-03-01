/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:39:30 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/01 22:47:15 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_stack_first(t_stack *stack, t_node *node)
{
    node->next = stack->top;
    node->prev = stack->top->prev;
    stack->top->prev->next = node;
    stack->top->prev = node;
    stack->top = node;
}

static void push(t_stack *stack_1, t_stack *stack_2)
{
    t_node *tmp;

    if (!stack_1 || !stack_1->top)
        return;
    tmp = stack_1->top;
    if (tmp->next == tmp)
        stack_1->top = NULL;
    else
    {
        stack_1->top->next->prev = stack_1->top->prev;
        stack_1->top->prev->next = stack_1->top->next;
        stack_1->top = stack_1->top->next;
    }
    if (!stack_2->top)
    {
        stack_2->top = tmp;
        tmp->next = tmp;
        tmp->prev = tmp;
    }
    else
        add_stack_first(stack_2, tmp);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}