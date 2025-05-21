/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:30:56 by sabe              #+#    #+#             */
/*   Updated: 2025/05/21 15:27:19 by sabe             ###   ########.fr       */
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
    if (node->token)
        free_token(node->token);
    free(node);
}

void	all_free_parser(t_parser *ps)
{
	if (!ps)
		return ;
	free_node(ps->tree->head);
	free(ps->tree);
	free(ps);
}
