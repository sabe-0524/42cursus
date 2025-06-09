/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/06/09 20:26:45 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

static void	do_pipe_exec(t_node *node, t_executor *ex)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	ex->out_fd = pipefd[1];
	recur_ex(node->left, ex);
	if (!ft_strcmp(my_getenv("?", ex->env), "130"))
	{
		if (pipefd[0] > STDERR_FILENO)
			close(pipefd[0]);
		if (pipefd[1] > STDERR_FILENO)
			close(pipefd[1]);
		return ;
	}
	if (pipefd[1] > STDERR_FILENO)
		close(pipefd[1]);
	ex->in_fd = pipefd[0];
	ex->out_fd = STDOUT_FILENO;
	recur_ex(node->right, ex);
	if (pipefd[0] > STDERR_FILENO)
		close(pipefd[0]);
}

static void	handle_pipe_node(t_node *node, t_executor *ex)
{
	ex->use_pipe = true;
	do_pipe_exec(node, ex);
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
