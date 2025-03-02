/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_r_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:56:26 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/02 16:16:53 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_stack(t_stack *stack)
{
  t_node *node;
  int count;

  if (!stack || !stack->top)
    return (0);
  count = 1;
  node = stack->top->next;
  while (node != stack->top)
  {
    node = node->next;
    count++;
  }
  return (count);
}

void assign_rb_rrb(t_node *node_a, int stack_len, int rb)
{
    node_a->command.rb = rb;
    if (rb == 0)
        node_a->command.rrb = 0;
    else
        node_a->command.rrb = stack_len - rb;
}

int count_if_min(t_node *node_a, t_stack *stack, int stack_len)
{
  t_node *node_b;
  int max;
  int is_first;
  int max_index;
  int i;

  i = 0;
  node_b = stack->top;
  max = node_b->content;
  is_first = 1;
  while (is_first || node_b != stack->top)
  {
    is_first = 0;
    if (node_a->content > node_b->content)
      return (0);
    if (max < node_b->content)
    {
      max = node_b->content;
      max_index = i;
    }
    node_b = node_b->next;
    i++;
  }
  assign_rb_rrb(node_a, stack_len, max_index);
  return (1);
}