/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:03:00 by sabe              #+#    #+#             */
/*   Updated: 2025/05/20 15:02:37 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

volatile sig_atomic_t	g_signal;

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

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_tokenizer	*tk;
	t_parser	*ps;
	t_env		*env;

	if (argc != 1 && argv[0])
		return (1);
	env = init_env(envp);
	my_setenv_row(env, "?", ft_itoa(EXIT_SUCCESS));
	while (1)
	{
		init_signal();
		line = readline("minishell$ ");
		if (line == NULL)
			break ;
		init_signal();
		if (is_line(line))
		{
			add_history(line);
			tk = tokenizer(line);
			if (!tk)
			{
				my_setenv_row(env, "?", ft_itoa(EXIT_FAILURE));
				continue ;
			}
			ps = parser(tk);
			if (is_error_ast(ps->tree))
			{
				ft_putendl_fd("sysntax error", 2);
				all_free_parser(ps);
				my_setenv_row(env, "?", ft_itoa(EXIT_FAILURE));
				continue ;
			}
			expander(ps->tree, env);
			exec(ps->tree, env);
      free_for_next(ps, tk);
		}
	}
  all_free_env(env);
	rl_clear_history();
	return (0);
}
