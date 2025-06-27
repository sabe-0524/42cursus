/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/06/27 15:53:04 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	do_pipe_exec(t_node *node, t_executor *ex)
{
	int	pipefd[2];
	int	saved_in;
	int	saved_out;

	saved_in = ex->in_fd;
	saved_out = ex->out_fd;
	create_pipe(pipefd);
	ex->pid = create_fork();
	if (ex->pid == 0)
	{
		handle_child(pipefd, saved_in, node, ex);
	}
	setup_parent(pipefd, saved_out, ex);
	recur_ex(node->right, ex);
	teardown_parent(pipefd, saved_in, saved_out, ex);
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
