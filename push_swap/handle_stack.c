/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:24:29 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/01 20:47:00 by abesouichir      ###   ########.fr       */
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

	i = 1;
  stack = (t_stack *)malloc(sizeof(t_stack));
  if (!stack)
      return (NULL);
	while (i < argc)
	{
		node = create_node(ft_atoi(argv[i]));
    if (!node)
        return (NULL); //全フリー処理を追加
    if (i == 1)
    {
        stack->top = node;
        node->next = node;
        node->prev = node;
    }
    else
        add_stack_last(stack, node);
    i++;
	}
  return (stack);
}
