/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:52:30 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 16:42:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int ex_export(t_node *node, t_executor *ex)
{
	t_token *tk;

	tk = node->token;

	while (tk)
	{
		my_setenv(ex->env, tk->content);
		tk = tk->next;
	}
	return (EXIT_SUCCESS);
}
