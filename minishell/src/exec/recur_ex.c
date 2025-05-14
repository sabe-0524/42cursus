/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/05/14 16:38:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	recur_ex(t_node *node, t_executor *ex)
{
	if (node->token->type == GENERAL)
	{
		ex_command(node, ex);
		return ;
	}
	else if (node->token->type == PIPE)
	{
		ex_pipe(ex);
	}
	// else if (node->token->type > PIPE)
	// {
	// 	ex_redirect(ex);
	// }
	recur_ex(node->left, ex);
	recur_ex(node->right, ex);
}
