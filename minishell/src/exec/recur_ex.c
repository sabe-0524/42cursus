/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 16:21:58 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	recur_ex(t_node *node, t_executor *ex)
{
	if (node->token->type == PIPE)
	{
		ex->save_in = ex->in_fd;
		if (pipe(ex->pipe_fd) < 0)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		ex->out_fd = ex->pipe_fd[1];
		recur_ex(node->left, ex);
		if (ex->pipe_fd[1] > STDERR_FILENO)
			close(ex->pipe_fd[1]);
		ex->in_fd = ex->pipe_fd[0];
		ex->out_fd = STDOUT_FILENO;
		recur_ex(node->right, ex);
		if (ex->pipe_fd[0] > STDERR_FILENO)
			close(ex->pipe_fd[0]);
		ex->in_fd = ex->save_in;
	}
	else if (node->token->type > PIPE)
	{
		ex_redirect(node, ex);
		recur_ex(node->right, ex);
	}
	else
	{
		ex_command_first(node, ex);
		waitpid(ex->pid, NULL, 0);
	}
}
