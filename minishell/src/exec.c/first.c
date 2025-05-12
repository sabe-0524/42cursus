/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:06:24 by sabe              #+#    #+#             */
/*   Updated: 2025/05/11 23:20:38 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	do_parent_first(t_executor *ex)
{
	if (ex->pipe_fd[0] != -1)
	{
		close(ex->pipe_fd[1]);
		ex->in_fd = ex->pipe_fd[0];
    ex->pipe_fd[0] = -1;
    ex->pipe_fd[1] = -1;
	}
}

void	do_child_first(t_node *node, t_executor *ex)
{
	char	**command;
	char	*filepath;

  if (ex->in_fd != STDIN_FILENO) {
    if (dup2(ex->in_fd, STDIN_FILENO) == -1)
    {
        perror("dup2 in_fd");
        exit(1);
    }
    close(ex->in_fd);
    ex->in_fd = STDIN_FILENO;
  }
	if (ex->pipe_fd[0] != -1)
	{
		dup2(ex->pipe_fd[1], STDOUT_FILENO);
		close(ex->pipe_fd[0]);
		close(ex->pipe_fd[1]);
    ex->pipe_fd[0] = -1;
    ex->pipe_fd[1] = -1;
	}
	command = make_command(node);
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
