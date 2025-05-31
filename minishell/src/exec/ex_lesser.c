/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lesser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:08:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:43:37 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_lesser(t_node *node, t_executor *ex)
{
	int	fd;

	if (ex->in_fd != STDIN_FILENO)
		close(ex->in_fd);
	fd = open(node->left->token->content, O_RDONLY);
	if (fd == -1)
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	ex->in_fd = fd;
	return (EXIT_SUCCESS);
}
