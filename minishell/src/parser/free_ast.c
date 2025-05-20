/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:30:56 by sabe              #+#    #+#             */
/*   Updated: 2025/05/20 14:56:44 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	free_token(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		free(token->content);
		free(token);
		token = next;
	}
}

void free_node(t_node *node)
{
    if (!node)
        return;

    free_node(node->left);
    free_node(node->right);
    free_token(node->token);
    free(node);
}

void	all_free_parser(t_parser *ps)
{
	if (!ps)
		return ;
	// free_node(ps->tree->head);
	free(ps->tree);
	free(ps);
}
