/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_lesser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:44:16 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 22:08:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	heredoc_child_loop(const char *delim, int write_fd)
{
	char	*line;

	heredoc_signal();
	while (1)
	{
		line = readline("> ");
		if (!line)
			exit(EXIT_FAILURE);
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, write_fd);
		free(line);
	}
	exit(0);
}

int	ex_r_lesser(t_node *node, t_executor *ex)
{
	pid_t	pid;
	int		status;

	if (pipe(ex->pipe_fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
	{
		close(ex->pipe_fd[0]);
		close(ex->pipe_fd[1]);
		exit(1);
	}
	else if (pid == 0)
	{
		close(ex->pipe_fd[0]);
		heredoc_signal();
		heredoc_child_loop(node->left->token->content, ex->pipe_fd[1]);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		close(ex->pipe_fd[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			ex->in_fd = ex->pipe_fd[0];
			return (0);
		}
		close(ex->pipe_fd[0]);
		ex->in_fd = STDIN_FILENO;
		return (130);
	}
	return (0);
}
