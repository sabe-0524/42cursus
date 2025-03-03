/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:03:41 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/04 01:37:49 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void do_command(t_stack *stack_a, t_stack *stack_b, char *line)
{
    if (!ft_strncmp(line, "ra", 3))
        stack_a->top = stack_a->top->next;
    if (!ft_strncmp(line, "rb", 3))
        stack_b->top = stack_b->top->next;
    if (!ft_strncmp(line, "rr", 3))
    {
        stack_a->top = stack_a->top->next;
        stack_b->top = stack_b->top->next;
    }
    if (!ft_strncmp(line, "rra", 4))
        stack_a->top = stack_a->top->prev;
    if (!ft_strncmp(line, "rrb", 4))
        stack_b->top = stack_b->top->prev;
    if (!ft_strncmp(line, "rrr", 4))
    {
        stack_a->top = stack_a->top->prev;
        stack_b->top = stack_b->top->prev;
    }
    if (!ft_strncmp(line, "pa", 3))
        push(stack_b, stack_a);
    if (!ft_strncmp(line, "pb", 3))
        push(stack_a, stack_b);
    if (!ft_strncmp(line, "sa", 3))
        swap(stack_a);
    if (!ft_strncmp(line, "sb", 3))
        swap(stack_b);
    if (!ft_strncmp(line, "ss", 3))
    {
        swap(stack_a);
        swap(stack_b);
    }
}

void convert_null(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n')
        i++;
    str[i] = '\0';
}

void execute_ps(t_stack *stack_a, t_stack *stack_b)
{
    char *line;

    line = get_next_line(0);
    while (line)
    {
        convert_null(line);
        do_command(stack_a, stack_b, line);
        line = get_next_line(0);
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    alert_error(argc, argv);
    stack_a = create_stack(argc, argv);
    if (!stack_a)
        exit(1);
    stack_b = create_stack(0, NULL);
    if (!stack_b)
    {
        all_free(stack_a);
        exit(1);
    }
    execute_ps(stack_a, stack_b);
    if (check_stack_sorted(stack_a) && stack_b->top == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    all_free(stack_a);
    free(stack_b);
    return (0);
}