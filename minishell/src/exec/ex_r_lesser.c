/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_lesser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:44:16 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:46:57 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	heredoc_child_loop(const char *delim, int write_fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (g_signal == 1)
			break ;
		if (!line)
			break ;
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, write_fd);
		free(line);
	}
	rl_clear_history();
	close(write_fd);
	if (g_signal == 1)
	{
		g_signal = 0;
		exit(130);
	}
	exit(0);
}

static pid_t	ex_r_lesser_fork(t_executor *ex)
{
	pid_t	pid;

	if (pipe(ex->pipe_fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
	{
		close(ex->pipe_fd[0]);
		close(ex->pipe_fd[1]);
		exit(1);
	}
	return (pid);
}

static int	ex_r_lesser_child(t_node *node, t_executor *ex)
{
	close(ex->pipe_fd[0]);
	heredoc_signal();
	heredoc_child_loop(node->left->token->content, ex->pipe_fd[1]);
	return (0);
}

static int	ex_r_lesser_parent(t_executor *ex, pid_t pid)
{
	int	status;

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

int	ex_r_lesser(t_node *node, t_executor *ex)
{
	pid_t	pid;

	pid = ex_r_lesser_fork(ex);
	if (pid == 0)
		return (ex_r_lesser_child(node, ex));
	else
		return (ex_r_lesser_parent(ex, pid));
}
