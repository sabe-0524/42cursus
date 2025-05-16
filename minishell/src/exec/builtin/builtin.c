/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:01:11 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 16:52:23 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

bool	is_builtin(t_node *node)
{
	char	*cmd;

	cmd = node->token->content;
	if (ft_strncmp(cmd, "echo", 4) == 0 || ft_strncmp(cmd, "cd", 2) == 0
		|| ft_strncmp(cmd, "pwd", 3) == 0 || ft_strncmp(cmd, "export", 6) == 0
		|| ft_strncmp(cmd, "unset", 5) == 0 || ft_strncmp(cmd, "env", 3) == 0
		|| ft_strncmp(cmd, "exit", 4) == 0)
		return (true);
	else
		return (false);
}

void	ex_builtin(t_node *node, t_executor *ex)
{
	if (ft_strncmp(node->token->content, "echo", 5) == 0)
		ex_echo(node, ex);
	// if (ft_strncmp(node->token->content, "cd", 3))
	// 	ex_cd(node, ex);
	// if (ft_strncmp(node->token->content, "pwd", 4))
	// 	ex_pwd(node, ex);
	if (ft_strncmp(node->token->content, "export", 7))
		ex_export(node, ex);
	if (ft_strncmp(node->token->content, "unset", 6))
		ex_unset(node, ex);
	// if (ft_strncmp(node->token->content, "env", 4))
	// 	ex_env(node, ex);
	// if (ft_strncmp(node->token->content, "exit", 5))
	// 	ex_exit(node, ex);
}
