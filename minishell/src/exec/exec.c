/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:25:12 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 20:22:17 by sabe             ###   ########.fr       */
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
	int			heredoc_status;

	heredoc_status = 0;
	ex = init_ex(tree, env);
	exec_heredoc(ex, tree->head, &heredoc_status);
	if (heredoc_status == 0)
	{
		recur_ex(tree->head, ex);
		wait_for_children(ex);
	}
	all_free_executor(ex);
}
