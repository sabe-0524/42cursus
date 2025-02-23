/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:14:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/02/23 21:21:24 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

typedef struct s_command
{
    int		all;
    int		ra;
    int		rra;
    int		rb;
    int		rrb;
    int		rr;
    int		rrr;
} t_command;

typedef struct s_stack
{
    int content;
    struct s_stack *next;
    struct s_stack *prev;
    t_command command;
} t_stack;

#endif