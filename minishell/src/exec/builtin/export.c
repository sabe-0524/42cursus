/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:52:30 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 17:54:42 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void ex_export(t_node *node, t_executor *ex)
{
	t_token *tk;

	tk = node->token;

	while (tk)
	{
		my_setenv(ex->env, tk->content);
		tk = tk->next;
	}
}
