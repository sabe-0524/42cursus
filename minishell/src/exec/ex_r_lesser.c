/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_lesser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:44:16 by sabe              #+#    #+#             */
/*   Updated: 2025/05/17 20:45:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void read_heredoc(t_node *node, t_executor *ex)
{
	char *line;

	if(pipe(ex->pipe_fd) < 0)
	{
		exit(1); // TODO
	}
	while (1)
	{
		line = readline("> ");
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
}

void ex_r_lesser(t_node *node, t_executor *ex)
{
	if (!node)
		exit(1);
	if (ex->in_fd != STDIN_FILENO)
		close(ex->in_fd);
	read_heredoc(node, ex);
}
