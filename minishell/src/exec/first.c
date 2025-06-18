/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:06:24 by sabe              #+#    #+#             */
/*   Updated: 2025/06/18 02:25:10 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	do_parent_first(t_executor *ex)
{
	if (ex->out_fd > STDERR_FILENO && ex->out_fd != STDOUT_FILENO)
		close(ex->out_fd);
}

int not_builtin(t_node *node, t_executor *ex)
{
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
    if (node->is_last)
      ex->last_pid = ex->pid;
    return (0);
  }
}

// int	ex_command_first(t_node *node, t_executor *ex)
// {
// 	if (is_builtin(node) && ex->use_pipe == false)
// 		return (ex_builtin(node, ex));
// 	ex->pid = fork();
// 	if (ex->pid < 0)
// 		exit(EXIT_FAILURE);
// 	else if (ex->pid == 0)
// 	{
// 		child_signal();
// 		do_child_first(node, ex);
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		parent_signal();
// 		do_parent_first(ex);
// 		return (0);
// 	}
// }

int	ex_command_first(t_node *node, t_executor *ex)
{
	if (is_builtin(node) && ex->use_pipe == false)
		return (ex_builtin(node, ex));
  else if (ex->use_pipe == false || node->is_last == true)
    return (not_builtin(node, ex));
	child_signal();
	do_child_first(node, ex);
	exit(EXIT_FAILURE);
}
