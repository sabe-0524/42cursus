/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:03:41 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/04 11:54:24 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void do_command(t_stack *stack_a, t_stack *stack_b, char *line)
{
    int flag;

    flag = 0;
    flag += do_r(stack_a, stack_b, line);
    flag += do_rr(stack_a, stack_b, line);
    flag += do_s(stack_a, stack_b, line);
    flag += do_p(stack_a, stack_b, line);
    if (!flag)
    {
        all_free(stack_a);
        all_free(stack_b);
        write(2, "Error\n", 6);
        exit(1);
    }
}

void convert_null(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n' && str[i] != '\0')
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
    all_free(stack_b);
    return (0);
}