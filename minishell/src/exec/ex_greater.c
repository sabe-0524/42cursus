/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_greater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:10:57 by sabe              #+#    #+#             */
/*   Updated: 2025/05/15 19:47:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	ex_greater(t_node *node, t_executor *ex)
{
	int	fd;

	if (ex->out_fd != STDOUT_FILENO)
		close(ex->out_fd);
	fd = open(node->left->token->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ex->out_fd = fd;
}
