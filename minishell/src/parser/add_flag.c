/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:32:10 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 20:40:24 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	add_flag(t_tree *tree)
{
	t_node	*node;

	node = tree->head;
	if (!node)
		return ;
	while (node->left)
		node = node->left;
	node->is_first = true;
	node = tree->head;
	while (node->right)
		node = node->right;
	node->is_last = true;
}
