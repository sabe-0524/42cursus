/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:06:24 by sabe              #+#    #+#             */
/*   Updated: 2025/05/22 21:48:58 by sabe             ###   ########.fr       */
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
	if (access(filepath, F_OK) != 0)
	{
		perror(NULL);
		exit(127);
	}
	if (is_dir(filepath) || access(filepath, X_OK) != 0)
	{
		ft_putendl_fd("Is a directory", 2);
		exit(126);
	}
	if (execve(filepath, command, catenv(ex->env)) == -1)
	{
		perror("execve");
		exit(1); // TODO
	}
}

int	ex_command_first(t_node *node, t_executor *ex)
{
	int	status;

	if (is_builtin(node))
		return (ex_builtin(node, ex));
	ex->pid = fork();
	if (ex->pid < 0)
		exit(EXIT_FAILURE);
	else if (ex->pid == 0)
	{
		child_signal();
		do_child_first(node, ex);
		exit(EXIT_FAILURE);
	}
	else
	{
		parent_signal();
		do_parent_first(ex);
		waitpid(ex->pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}
