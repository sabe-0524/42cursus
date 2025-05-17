/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:23:50 by sabe              #+#    #+#             */
/*   Updated: 2025/05/17 20:34:24 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	ex_exit(t_node *node, t_executor *ex)
{
	if (count_token(node) > 2)
	{
		exit(1); // TODO
	}
	else if (count_token(node) == 2)
		exit(node->token->next->content);
	else
		exit(my_getenv("?", ex->env));
}
