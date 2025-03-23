/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:14:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/23 16:05:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	int				all;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
}					t_command;

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	t_command		command;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

t_node				*create_node(int content);
t_stack				*create_stack(int argc, char **argv);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
int					count_stack(t_stack *stack);
void				assign_rb_rrb(t_node *node_a, int stack_len, int rb);
int					count_if_min(t_node *node_a, t_stack *stack, int stack_len);
void				count_r(t_stack *stack_a, t_stack *stack_b);
void				sort_under_three(t_stack *stack);
void				delete_except_ra_rb(t_node *node);
void				delete_except_ra_rrb(t_node *node);
void				delete_except_rra_rb(t_node *node);
void				delete_except_rra_rrb(t_node *node);
void				total_score(t_node *node);
t_node				*get_max_node(t_stack *stack);
void				sort(t_stack *stack_a, t_stack *stack_b);
void				alert_error(int argc, char **argv);
int					check_stack_sorted(t_stack *stack);
t_stack				*all_free(t_stack *stack);
void				swap(t_stack *stack);
void				push(t_stack *stack_1, t_stack *stack_2);
void				sort_under_three(t_stack *stack);
void				push_back(t_stack *stack_a, t_stack *stack_b);
t_node				*get_min_node(t_stack *stack);
void				rotate_min(t_stack *stack);

#endif
