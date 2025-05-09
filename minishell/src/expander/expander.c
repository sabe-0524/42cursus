/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 15:13:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	recur_expand(t_node *node)
{
	if (node->token->type == GENERAL)
	{
		expand();
		return ;
	}
	recur_expand(node->left);
	recur_expand(node->right);
}

void	expander(t_tree *tree)
{
	t_node	*node;

	node = tree->head;
	recur_expand(node);
}
