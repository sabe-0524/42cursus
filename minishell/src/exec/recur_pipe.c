/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:12:39 by sabe              #+#    #+#             */
/*   Updated: 2025/06/21 18:00:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

pid_t	create_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	handle_child(int pipefd[2], int saved_in, t_node *node, t_executor *ex)
{
	if (saved_in != STDIN_FILENO)
	{
		dup2(saved_in, STDIN_FILENO);
		close(saved_in);
	}
	ex->in_fd = STDIN_FILENO;
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	ex->out_fd = STDOUT_FILENO;
	recur_ex(node->left, ex);
	exit(EXIT_FAILURE);
}

void	setup_parent(int pipefd[2], int saved_out, t_executor *ex)
{
	close(pipefd[1]);
	ex->in_fd = pipefd[0];
	ex->out_fd = saved_out;
}

void	teardown_parent(int pipefd[2], int saved_in, int saved_out,
		t_executor *ex)
{
	close(pipefd[0]);
	ex->in_fd = saved_in;
	ex->out_fd = saved_out;
}
