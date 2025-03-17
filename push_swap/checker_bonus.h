/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:02:24 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/17 20:12:14 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"

int	do_r(t_stack *stack_a, t_stack *stack_b, char *line);
int	do_rr(t_stack *stack_a, t_stack *stack_b, char *line);
int	do_s(t_stack *stack_a, t_stack *stack_b, char *line);
int	do_p(t_stack *stack_a, t_stack *stack_b, char *line);

#endif
