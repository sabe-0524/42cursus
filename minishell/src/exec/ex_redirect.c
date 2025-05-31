/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:03:58 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:44:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_redirect(t_node *node, t_executor *ex)
{
	if (node->token->type == LESSER)
		return (ex_lesser(node, ex));
	else if (node->token->type == GREATER)
		return (ex_greater(node, ex));
	else if (node->token->type == R_LESSER)
		return (ex_r_lesser(node, ex));
	else
		return (ex_r_greater(node, ex));
}
