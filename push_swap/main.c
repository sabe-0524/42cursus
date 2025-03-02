/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:52 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/02 16:42:13 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_stack *stack)
{
    t_node *node;
    node = stack->top;
    int i = 0;
    while (i < 5)
    {
        printf("%d\n", node->content);
        printf("ra:%d rra:%d rb:%d rrb:%d rr:%d, rrr:%d\n", node->command.ra, node->command.rra, node->command.rb, node->command.rrb, node->command.rr, node->command.rrr);
        node = node->next;
        i++;
    }
}

int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char  *test[] = {"0", "5", "1", "7", "8"};

    stack_a = create_stack(argc, argv);
    stack_b = create_stack(5, test);
    count_r(stack_a, stack_b);
    test_print(stack_a);
    return (0);
}
