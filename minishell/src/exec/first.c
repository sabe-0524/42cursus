/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:06:24 by sabe              #+#    #+#             */
/*   Updated: 2025/05/14 17:02:54 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	do_parent_first(t_executor *ex)
{
	if (ex->out_fd != -1)
		close(ex->out_fd);
}

void	do_child_first(t_node *node, t_executor *ex)
{
	char	**command;
	char	*filepath;

	if (ex->in_fd != STDIN_FILENO)
	{
		if (dup2(ex->in_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 in_fd");
			exit(1);
		}
		close(ex->in_fd);
	}
	if (ex->out_fd != STDOUT_FILENO)
	{
		dup2(ex->out_fd, STDOUT_FILENO);
		close(ex->out_fd);
	}
	if (ex->pipe_fd[0] != -1)
		close(ex->pipe_fd[0]);
	command = make_shellcommand(node);
	filepath = make_filepath(command);
	if (execve(filepath, command, ex->envp) == -1)
	{
		perror("execve");
		exit(1); // TODO
	}
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
