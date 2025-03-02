/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:54:46 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/02 17:20:06 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  sort_under_three(t_stack *stack)
{
    int stack_len;

    stack_len = count_stack(stack);
    if (stack_len == 1)
        return;
    else if (stack_len == 2)
    {
        if (stack->top->content > stack->top->next->content)
            sa(stack);
        return;
    }
    else
    {
        if (stack->top->content > stack->top->next->content && stack->top->content > stack->top->prev->content)
            ra(stack);
        else if (stack->top->content < stack->top->next->content && stack->top->prev->content < stack->top->next->content)
            rra(stack);
        if (stack->top->content > stack->top->next->content)
            sa(stack);
    }
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
    if (count_stack(stack_a) <= 3)
    {
        sort_under_three(stack_a);
        return;
    }
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    while (count_stack(stack_a) > 3)
    {
        
    }
}