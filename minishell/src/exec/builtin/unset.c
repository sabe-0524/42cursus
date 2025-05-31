/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:14:35 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/31 18:42:29 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_unset(t_node *node, t_executor *ex)
{
	t_token	*tk;

	tk = node->token;
	while (tk)
	{
		my_unset(ex->env, tk->content);
		tk = tk->next;
	}
	return (EXIT_SUCCESS);
}
