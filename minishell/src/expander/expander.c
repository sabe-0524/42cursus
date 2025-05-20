/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/20 14:12:10 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	recur_expand(t_node *node, t_env *env)
{
	if (!node)
		return ;
	if (node->token->type == GENERAL)
	{
		expand_word(node, env);
		return ;
	}
	recur_expand(node->left, env);
	recur_expand(node->right, env);
}

void	expander(t_tree *tree, t_env *env)
{
	recur_expand(tree->head, env);
}
