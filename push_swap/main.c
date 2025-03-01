/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:52 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/01 22:37:47 by abesouichir      ###   ########.fr       */
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
        node = node->next;
        i++;
    }
}

int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char  *test[] = {"a", "5", "6", "7"};

    stack_a = create_stack(argc, argv);
    stack_b = create_stack(4, test);
    pa(stack_a, stack_b);
    test_print(stack_a);
    write(1, "\n", 1);
    test_print(stack_b);
    return (0);
}
