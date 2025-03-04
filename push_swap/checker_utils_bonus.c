/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:44:59 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/04 12:03:37 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int do_r(t_stack *stack_a, t_stack *stack_b, char *line)
{
    if (!ft_strncmp(line, "ra", 3))
    {
        if (stack_a->top)
            stack_a->top = stack_a->top->next;
    }
    else if (!ft_strncmp(line, "rb", 3))
    {
        if (stack_b->top)
            stack_b->top = stack_b->top->next;
    }
    else if (!ft_strncmp(line, "rr", 3))
    {
        if (stack_a->top && stack_b->top)
        {
            stack_a->top = stack_a->top->next;
            stack_b->top = stack_b->top->next;
        }
    }
    else
        return (0);
    return (1);
}

int do_rr(t_stack *stack_a, t_stack *stack_b, char *line)
{
    if (!ft_strncmp(line, "rra", 4))
    {
        if (stack_a->top)
            stack_a->top = stack_a->top->prev;
    }
    else if (!ft_strncmp(line, "rrb", 4))
    {
        if (stack_b->top)
            stack_b->top = stack_b->top->prev;
    }
    else if (!ft_strncmp(line, "rrr", 4))
    {
        if (stack_a->top && stack_b->top)
        {
            stack_a->top = stack_a->top->prev;
            stack_b->top = stack_b->top->prev;
        }
    }
    else
        return (0);
    return (1);
}

int do_p(t_stack *stack_a, t_stack *stack_b, char *line)
{
    if (!ft_strncmp(line, "pa", 3))
    {
        if (stack_b->top)
            push(stack_b, stack_a);
    }
    else if (!ft_strncmp(line, "pb", 3))
    {
        if (stack_a->top)
            push(stack_a, stack_b);
    }
    else
        return (0);
    return (1);
}

int do_s(t_stack *stack_a, t_stack *stack_b, char *line)
{
    if (!ft_strncmp(line, "sa", 3))
    {
        if (stack_a->top)
            swap(stack_a);
    }
    else if (!ft_strncmp(line, "sb", 3))
    {
        if (stack_b->top)
            swap(stack_b);
    }
    else if (!ft_strncmp(line, "ss", 3))
    {
        if (stack_a->top && stack_b->top)
        {
            swap(stack_a);
            swap(stack_b);
        }
    }
    else
        return (0);
    return (1);
}