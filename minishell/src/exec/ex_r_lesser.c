/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_lesser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:44:16 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 17:53:29 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	cancel_heredoc(char *line, t_executor *ex)
{
	if (line)
		free(line);
	close(ex->pipe_fd[1]);
	ex->in_fd = STDIN_FILENO;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	g_signal = 0;
}

int	read_heredoc(t_node *node, t_executor *ex)
{
	char	*line;

	if (pipe(ex->pipe_fd) < 0)
	{
		exit(1); // TODO
	}
	while (1)
	{
		line = readline("> ");
		if (g_signal == 1)
		{
			cancel_heredoc(line, ex);
			return (130);
		}
		if (line == NULL)
			break ;
		if (ft_strcmp(line, node->left->token->content) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, ex->pipe_fd[1]);
		free(line);
	}
	close(ex->pipe_fd[1]);
	ex->in_fd = ex->pipe_fd[0];
	return (0);
}

int	ex_r_lesser(t_node *node, t_executor *ex)
{
	heredoc_signal();
	if (ex->in_fd != STDIN_FILENO)
		close(ex->in_fd);
	return (read_heredoc(node, ex));
}
