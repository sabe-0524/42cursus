/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:07:51 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/02 19:51:07 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void count_ra_rra(t_node *node, int i, int stack_len)
{
    node->command.ra = i;
    if (i == 0)
        node->command.rra = 0;
    else
        node->command.rra = stack_len - i;
}

void count_rb_rrb(t_node *node_a, t_stack *stack, int stack_len)
{
    t_node *node_b;
    int i;
    int rb;
    int is_first;
    int max;
    
    if (count_if_min(node_a, stack, stack_len))
        return;
    node_b = stack->top;
    is_first = 1;
    i = 0;
    max = INT_MIN;
    rb = 0;
    while (is_first || node_b != stack->top)
    {
        is_first = 0;
        if (node_b->content < node_a->content && node_b->content >= max)
        {
            rb = i;
            max = node_b->content;
        }
        i++;
        node_b = node_b->next;
    }
    assign_rb_rrb(node_a, stack_len, rb);
}

void  count_rr_and_rrr(t_node *node_a)
{
    int rr;
    int rrr;

    rr = ft_min(node_a->command.ra, node_a->command.rb);
    node_a->command.rr = rr;
    rrr = ft_min(node_a->command.rra, node_a->command.rrb);
    node_a->command.rrr = rrr;
}

void count_r(t_stack *stack_a, t_stack *stack_b)
{
    t_node *node_a;
    int i;
    int stack_a_len;
    int stack_b_len;
    int is_first;
    
    i = 0;
    is_first = 1;
    stack_a_len = count_stack(stack_a);
    stack_b_len = count_stack(stack_b);
    node_a = stack_a->top;
    while (is_first || node_a != stack_a->top)
    {
        
        is_first = 0;
        count_ra_rra(node_a, i, stack_a_len);
        count_rb_rrb(node_a, stack_b, stack_b_len);
        count_rr_and_rrr(node_a);
        total_score(node_a);
        node_a = node_a->next;
        i++;
    }
}