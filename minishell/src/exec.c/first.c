/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:06:24 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 22:07:42 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	do_parent_first(t_executor *ex)
{
	if (ex->pipe_fd[0] != -1)
	{
		close(ex->pipe_fd[1]);
		ex->in_fd = ex->pipe_fd[0];
	}
}

void	do_child_first(t_node *node, t_executor *ex)
{
	char	**command;
	char	filepath;

	if (ex->pipe_fd[0] != -1)
	{
		dup2(ex->pipe_fd[1], STDOUT_FILENO);
		close(ex->pipe_fd[0]);
		close(ex->pipe_fd[1]);
	}
	command = make_command(node);
	filepath = make_filepath(command);
}

void	ex_command_first(t_node *node, t_executor *ex)
{
	ex->pid = fork();
	if (ex->pid < 0)
	{
		exit(1); // TODO
	}
	else if (ex->pid == 0)
		do_child_first(node, ex);
	else
		do_parent_first(ex);
}
