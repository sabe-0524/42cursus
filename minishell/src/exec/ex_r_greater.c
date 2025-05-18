/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:12:24 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 17:11:12 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_r_greater(t_node *node, t_executor *ex)
{
	int	fd;

	if (ex->out_fd != STDOUT_FILENO)
		close(ex->out_fd);
	fd = open(node->left->token->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	ex->out_fd = fd;
	return (EXIT_SUCCESS);
}
