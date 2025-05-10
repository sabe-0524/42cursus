/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:03:00 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 13:34:54 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_token(t_token *token)
{
	while (token)
	{
		printf("content:%s type:%u\n", token->content, token->type);
		token = token->next;
	}
}

static void	print_tree_rec(t_node *node, int depth)
{
	t_token	*tk;

	if (!node)
		return ;
	// 右サブツリーを先に出力（縦方向に上に表示）
	print_tree_rec(node->right, depth + 1);
	// インデント（depth に応じてスペースを挿入）
	for (int i = 0; i < depth; i++)
		printf("    ");
	// ノード自身のトークンリストを表示
	tk = node->token;
	while (tk)
	{
		if (tk->content)
			printf("%s", tk->content);
		else
			printf("(null)");
		if (tk->next)
			printf(" ");
		tk = tk->next;
	}
	printf("\n");
	// 左サブツリーを出力（縦方向に下に表示）
	print_tree_rec(node->left, depth + 1);
}

void	print_tree(t_tree *tree)
{
	// ツリー全体を深さ 0 から出力
	print_tree_rec(tree->head, 0);
}

int	main(void)
{
	char		*line;
	t_tokenizer	*tk;
	t_parser	*ps;

	while ((line = readline("minishell$ ")) != NULL)
	{
		if (*line)
		{
			add_history(line);
		}
		tk = tokenizer(line);
		ps = parser(tk);
		expander(ps->tree);
		printf("%d\n", is_error_ast(ps->tree));
		print_tree(ps->tree);
		all_free_parser(ps);
		free(tk->line);
		free(tk);
	}
	return (0);
}
