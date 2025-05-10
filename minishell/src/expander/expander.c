/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 13:25:20 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	recur_expand(t_node *node)
{
	if (node->token->type == GENERAL)
	{
		expand_word(node);
		return ;
	}
	recur_expand(node->left);
	recur_expand(node->right);
}

void	expander(t_tree *tree)
{
	recur_expand(tree->head);
}
