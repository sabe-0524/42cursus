/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lesser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:08:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/14 20:29:04 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void ex_lesser(t_node *node, t_executor *ex)
{
	int fd;

	if (!ex)
		exit(1);
	fd = open(node->left->token->content, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
}
