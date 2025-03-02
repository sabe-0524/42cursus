/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:22:25 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/02 20:50:41 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *get_max_node(t_stack *stack)
{
    t_node *node;
    t_node *max_node;
    int is_first;

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