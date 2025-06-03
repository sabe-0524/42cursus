/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/06/03 17:33:34 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

static void	handle_pipe_node(t_node *node, t_executor *ex)
{
	ex->use_pipe = true;
	ex->save_in = ex->in_fd;
	if (pipe(ex->pipe_fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	ex->out_fd = ex->pipe_fd[1];
	recur_ex(node->left, ex);
	if (!ft_strcmp(my_getenv("?", ex->env), "130"))
		return ;
	if (ex->pipe_fd[1] > STDERR_FILENO)
		close(ex->pipe_fd[1]);
	ex->in_fd = ex->pipe_fd[0];
	ex->out_fd = STDOUT_FILENO;
	recur_ex(node->right, ex);
	if (ex->pipe_fd[0] > STDERR_FILENO)
		close(ex->pipe_fd[0]);
	ex->in_fd = ex->save_in;
}

static void	handle_redirect_node(t_node *node, t_executor *ex)
{
	int	exit_code;

	exit_code = ex_redirect(node, ex);
	my_setenv_row(ex->env, "?", ft_itoa(exit_code));
	if (exit_code == 0 && node->right)
		recur_ex(node->right, ex);
}

static void	handle_command_node(t_node *node, t_executor *ex)
{
	int	exit_code;

	exit_code = ex_command_first(node, ex);
	if (node->is_last)
		ex->last_pid = ex->pid;
	my_setenv_row(ex->env, "?", ft_itoa(exit_code));
}

void	recur_ex(t_node *node, t_executor *ex)
{
	if (ft_strlen(node->token->content) == 0)
		return ;
	else if (node->token->type == PIPE)
		handle_pipe_node(node, ex);
	else if (node->token->type > PIPE)
		handle_redirect_node(node, ex);
	else
		handle_command_node(node, ex);
}
