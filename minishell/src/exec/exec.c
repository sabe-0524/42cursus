/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:25:12 by sabe              #+#    #+#             */
/*   Updated: 2025/06/25 22:01:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <tokenizer.h>

static void	handle_last_status(t_executor *ex, int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			write(STDERR_FILENO, "Quit (core dumped)\n", 19);
		my_setenv_row(ex->env, "?", ft_itoa(128 + WTERMSIG(status)));
	}
	else
	{
		my_setenv_row(ex->env, "?", ft_itoa(WEXITSTATUS(status)));
	}
}

static void	wait_for_children(t_executor *ex)
{
	int		status;
	pid_t	wpid;

	while (1)
	{
		wpid = wait(&status);
		if (wpid == -1)
		{
			if (errno == ECHILD)
				break ;
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (wpid == ex->last_pid)
			handle_last_status(ex, status);
	}
}

void	exec(t_tree *tree, t_env *env)
{
	t_executor	*ex;

	ex = init_ex(tree, env);

	// ヒアドキュメントのリダイレクトをパイプの前に処理する
	// パイプの左側がヒアドキュメントの場合、先にヒアドキュメントを処理して一時ファイルを作成する
	if (tree->head->token->type == PIPE && tree->head->left->token->type == R_LESSER)
	{
		ex_r_lesser(tree->head->left, ex);
	}

	recur_ex(tree->head, ex);
	wait_for_children(ex);
	all_free_executor(ex);
}


