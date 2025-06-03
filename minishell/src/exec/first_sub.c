/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:52:33 by sabe              #+#    #+#             */
/*   Updated: 2025/06/03 17:33:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

static void	redirect_std_fds(t_executor *ex)
{
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
		if (dup2(ex->out_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 out_fd");
			exit(1);
		}
		close(ex->out_fd);
	}
}

static void	close_pipe_read_end(t_executor *ex)
{
	if (ex->pipe_fd[0] > STDERR_FILENO)
		close(ex->pipe_fd[0]);
}

static void	check_filepath_and_permissions(const char *filepath)
{
	struct stat	sb;

	if (access(filepath, F_OK) != 0)
	{
		perror(NULL);
		exit(127);
	}
	if (stat(filepath, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ft_putendl_fd("Is a directory", 2);
		exit(126);
	}
	if (access(filepath, X_OK) != 0)
	{
		ft_putendl_fd("Permission denied", 2);
		exit(126);
	}
}

static void	exec_command(char **command, char *filepath, t_executor *ex)
{
	char	**envp;

	envp = catenv(ex->env);
	if (execve(filepath, command, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
}

void	do_child_first(t_node *node, t_executor *ex)
{
	char	**command;
	char	*filepath;

	redirect_std_fds(ex);
	close_pipe_read_end(ex);
	if (is_builtin(node))
	{
		ex->out_fd = STDOUT_FILENO;
		exit(ex_builtin(node, ex));
	}
	command = make_shellcommand(node);
	filepath = make_filepath(command, ex);
	check_filepath_and_permissions(filepath);
	exec_command(command, filepath, ex);
}
