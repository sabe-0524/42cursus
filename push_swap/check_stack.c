/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:14:19 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/03 20:38:29 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_stack_sorted(t_stack *stack)
{
    t_node *node;
    int is_first;

    node = stack->top;
    is_first = 1;
    while (is_first || node->next != stack->top)
    {
        is_first = 0;
        if (node->content > node->next->content || node->next == node)
            return;
        node = node->next;
    }
    all_free(stack);
    exit(0);
}

