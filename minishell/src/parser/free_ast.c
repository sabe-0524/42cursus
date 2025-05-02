/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:30:56 by sabe              #+#    #+#             */
/*   Updated: 2025/05/02 21:43:38 by sabe             ###   ########.fr       */
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

// void	free_node(t_node *node)
// {
// 	if (!node->token)
// 	{
// 		free(node);
// 		return ;
// 	}
// 	else
// 	{
// 		free_node(node->left);
// 		free_node(node->right);
// 		free_token(node->token);
// 	}
// }

void free_node(t_node *node)
{
    if (!node)
        return;              // ① NULL チェックを最初に入れる

    free_node(node->left);    // ② 左を解放
    free_node(node->right);   // ③ 右を解放
    free_token(node->token);  // ④ トークンリストを解放
    free(node);               // ⑤ 自分自身を解放
}

void	all_free_parser(t_parser *ps)
{
	if (!ps)
		return ;
	free_node(ps->tree->head);
	free(ps->tree);
	free(ps);
}
