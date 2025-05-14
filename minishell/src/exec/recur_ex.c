/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/05/14 17:16:39 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

// void	recur_ex(t_node *node, t_executor *ex)
// {
// 	if (node->token->type == GENERAL)
// 	{
// 		ex_command(node, ex);
// 		return ;
// 	}
// 	else if (node->token->type == PIPE)
// 	{
// 		ex_pipe(ex);
// 	}
// 	// else if (node->token->type > PIPE)
// 	// {
// 	// 	ex_redirect(ex);
// 	// }
// 	recur_ex(node->left, ex);
// 	recur_ex(node->right, ex);
// }

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
		close(ex->pipe_fd[1]);
		ex->in_fd = ex->pipe_fd[0];
		ex->out_fd = STDOUT_FILENO;
		recur_ex(node->right, ex);
		close(ex->pipe_fd[0]);
		// ex->in_fd = ex->save_in;
	}
	else
	{
		ex_command_first(node, ex);
		waitpid(ex->pid, NULL, 0);
	}
}
