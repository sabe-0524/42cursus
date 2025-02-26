/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:24:29 by abesouichir       #+#    #+#             */
/*   Updated: 2025/02/23 21:53:56 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int content)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

t_stack *create_stack(int argc, char **argv)
{
    int i;
    t_stack *stack;

    i = 0;
    while (i < argc)
    {
        stack = create_node(ft_atoi(argv[i]));
        
    }
}