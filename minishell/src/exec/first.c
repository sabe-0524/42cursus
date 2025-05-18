/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:06:24 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 15:22:19 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	do_parent_first(t_executor *ex)
{
	if (ex->out_fd > STDERR_FILENO && ex->out_fd != STDOUT_FILENO)
		close(ex->out_fd);
}

void	do_child_first(t_node *node, t_executor *ex)
{
	char	**command;
	char	*filepath;

	if (ex->in_fd > STDERR_FILENO)
	{
		if (dup2(ex->in_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 in_fd");
			exit(1);
		}
		close(ex->in_fd);
	}
	if (ex->out_fd > STDERR_FILENO)
	{
		dup2(ex->out_fd, STDOUT_FILENO);
		close(ex->out_fd);
	}
	if (ex->pipe_fd[0] > STDERR_FILENO)
		close(ex->pipe_fd[0]);
	command = make_shellcommand(node);
	filepath = make_filepath(command, ex);
	if (execve(filepath, command, catenv(ex->env)) == -1)
	{
		perror("execve");
		exit(1); // TODO
	}
}

void	ex_command_first(t_node *node, t_executor *ex)
{
	if (is_builtin(node))
	{
		ex_builtin(node, ex);
		return ;
	}
	ex->pid = fork();
	if (ex->pid < 0)
	{
		exit(1); // TODO
	}
	else if (ex->pid == 0)
	{
		child_signal();
		do_child_first(node, ex);
	}
	else
	{
		parent_signal();
		do_parent_first(ex);
	}
}
