/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:24:29 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/03 20:06:27 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void add_stack_last(t_stack *stack, t_node *node)
{
    node->next = stack->top;
    node->prev = stack->top->prev;
    stack->top->prev->next = node;
    stack->top->prev = node;
}

t_stack	*create_stack(int argc, char **argv)
{
	int i;
  t_stack *stack;
	t_node *node;

	i = 0;
  stack = (t_stack *)malloc(sizeof(t_stack));
  if (!stack)
      return (NULL);
	while (++i < argc)
	{
		node = create_node(ft_atoi(argv[i]));
    if (!node)
        return (all_free(stack));
    if (i == 1)
    {
        stack->top = node;
        node->next = node;
        node->prev = node;
    }
    else
        add_stack_last(stack, node);
	}
  return (stack);
}

t_stack *all_free(t_stack *stack)
{
    t_node *node;
    t_node *next;
    int is_first;

    is_first = 1;
    node = stack->top;
    while (is_first || node != stack->top)
    {
        is_first = 0;
        next = node->next;
        node->next = NULL;
        node->prev = NULL;
        free(node);
        node = next;
    }
    free(stack);
    return (NULL);
}
