/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:43:34 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/17 20:06:24 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_except_ra_rb(t_node *node)
{
	node->command.ra -= node->command.rr;
	node->command.rb -= node->command.rr;
	node->command.rra = 0;
	node->command.rrb = 0;
	node->command.rrr = 0;
}

void	delete_except_ra_rrb(t_node *node)
{
	node->command.rb = 0;
	node->command.rr = 0;
	node->command.rra = 0;
	node->command.rrr = 0;
}

void	delete_except_rra_rb(t_node *node)
{
	node->command.ra = 0;
	node->command.rr = 0;
	node->command.rrb = 0;
	node->command.rrr = 0;
}

void	delete_except_rra_rrb(t_node *node)
{
	node->command.rra -= node->command.rrr;
	node->command.rrb -= node->command.rrr;
	node->command.ra = 0;
	node->command.rb = 0;
	node->command.rr = 0;
}
