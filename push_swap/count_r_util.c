/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_r_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:56:26 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/02 21:37:11 by abesouichir      ###   ########.fr       */
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
  int max_index;
  int i;

  i = 0;
  node_b = stack->top;
  max = node_b->content;
  max_index = 0;
  while (!i || node_b != stack->top)
  {
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

int min_four(int a, int b, int c, int d)
{
    int min;

    min = a;
    if (min > b)
        min = b;
    if (min > c)
        min = c;
    if (min > d)
        min = d;
    return (min);
}

void total_score(t_node *node)
{
    int ra_rb;
    int ra_rrb;
    int rra_rb;
    int rra_rrb;
    int all;

    ra_rb = node->command.ra + node->command.rb - node->command.rr;
    ra_rrb = node->command.ra + node->command.rrb;
    rra_rb = node->command.rra + node->command.rb;
    rra_rrb = node->command.rra + node->command.rrb - node->command.rrr;
    all = min_four(ra_rb, ra_rrb, rra_rb, rra_rrb);
    node->command.all = all;
    if (all == ra_rb)
        delete_except_ra_rb(node);
    else if (all == ra_rrb)
        delete_except_ra_rrb(node);
    else if (all == rra_rb)
        delete_except_rra_rb(node);
    else
        delete_except_rra_rrb(node);
}