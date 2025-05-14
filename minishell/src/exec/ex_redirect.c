/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:03:58 by sabe              #+#    #+#             */
/*   Updated: 2025/05/14 20:17:18 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void ex_redirect(t_node *node, t_executor *ex)
{
	if (node->token->type == LESSER)
		ex_lesser(node, ex);
	else if (node->token->type == GREATER)
		ex_greater(node, ex);
	// else if (node->token->type == R_LESSER)
	// 	ex_r_lesser(node, ex);
	else if (node->token->type == R_GREATER)
		ex_r_greater(node, ex);
}
