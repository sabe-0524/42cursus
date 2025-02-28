/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:14:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/01 22:09:07 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

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

t_node	*create_node(int content);
t_stack	*create_stack(int argc, char **argv);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack_a, t_stack *stack_b);
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);

#endif
