/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:01:11 by sabe              #+#    #+#             */
/*   Updated: 2025/06/28 14:31:12 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

bool	is_builtin(t_node *node)
{
	char	*cmd;

	cmd = node->token->content;
	if (ft_strncmp(cmd, "echo", 5) == 0 || ft_strncmp(cmd, "cd", 3) == 0
		|| ft_strncmp(cmd, "pwd", 4) == 0 || ft_strncmp(cmd, "export", 7) == 0
		|| ft_strncmp(cmd, "unset", 6) == 0 || ft_strncmp(cmd, "env", 4) == 0
		|| ft_strncmp(cmd, "exit", 5) == 0)
		return (true);
	else
		return (false);
}

int	ex_builtin(t_node *node, t_executor *ex)
{
	if (ft_strncmp(node->token->content, "echo", 5) == 0)
		return (ex_echo(node, ex));
	if (ft_strncmp(node->token->content, "cd", 3) == 0)
		return (ex_cd(node, ex));
	if (ft_strncmp(node->token->content, "pwd", 4) == 0)
		return (ex_pwd(ex));
	if (ft_strncmp(node->token->content, "export", 7) == 0)
		return (ex_export(node, ex));
	if (ft_strncmp(node->token->content, "unset", 6) == 0)
		return (ex_unset(node, ex));
	if (ft_strncmp(node->token->content, "env", 4) == 0)
		return (ex_env(node, ex));
	if (ft_strncmp(node->token->content, "exit", 5) == 0)
		return (ex_exit(node, ex));
	return (EXIT_FAILURE);
}
