/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:02:24 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/04 11:53:37 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

int do_r(t_stack *stack_a, t_stack *stack_b, char *line);
int do_rr(t_stack *stack_a, t_stack *stack_b, char *line);
int do_s(t_stack *stack_a, t_stack *stack_b, char *line);
int do_p(t_stack *stack_a, t_stack *stack_b, char *line);

#endif