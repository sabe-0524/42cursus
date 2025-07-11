/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:49:58 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:00:05 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

bool	check_node(t_node *node)
{
	if (node->token->type == PIPE && node->left && node->right)
		return (false);
	if (node->token->type > PIPE && node->left)
		return (false);
	else
		return (true);
}

bool	recur_check(t_node *node)
{
	if (!node || node->token->type == GENERAL)
		return (false);
	else
	{
		if (recur_check(node->left))
			return (true);
		if (check_node(node))
			return (true);
		if (recur_check(node->right))
			return (true);
	}
	return (false);
}

bool	is_error_ast(t_tree *tree)
{
	t_node	*node;

	if (!tree)
		return (false);
	node = tree->head;
	if (!node)
		return (false);
	return (recur_check(node));
}
