/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_lesser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:44:16 by sabe              #+#    #+#             */
/*   Updated: 2025/06/27 15:51:07 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_r_lesser(t_node *node, t_executor *ex)
{
	int	fd;

	if (ex->in_fd != STDIN_FILENO)
		close(ex->in_fd);
	fd = open(node->heredoc_tmpfile, O_RDONLY);
	unlink(node->heredoc_tmpfile);
	if (fd == -1)
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	ex->in_fd = fd;
	return (EXIT_SUCCESS);
}
