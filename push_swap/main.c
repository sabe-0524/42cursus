/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:52 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/04 11:38:44 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_stack *stack)
{
    t_node *node;
    node = stack->top;
    int i = 0;
    while (i < 10)
    {
        printf("%d\n", node->content);
        // printf("ra:%d rb:%d rr:%d rra:%d rrb:%d rrr:%d\n", node->command.ra, node->command.rb, node->command.rr, node->command.rra, node->command.rrb, node->command.rrr);
        node = node->next;
        i++;
    }
}

int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    alert_error(argc, argv);
    stack_a = create_stack(argc, argv);
    if (!stack_a)
        exit(1);
    if (check_stack_sorted(stack_a))
    {
        all_free(stack_a);
        return (0);
    }
    stack_b = create_stack(0, NULL);
    if (!stack_b)
    {
        all_free(stack_a);
        exit(1);
    }
    sort(stack_a, stack_b);
    all_free(stack_a);
    all_free(stack_b);
    return (0);
}
