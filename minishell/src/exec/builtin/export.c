/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:52:30 by sabe              #+#    #+#             */
/*   Updated: 2025/06/09 17:47:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_export(t_node *node, t_executor *ex)
{
	t_token	*tk;
	int		flag;

	flag = 0;
	tk = node->token;
	while (tk)
	{
		if (my_setenv(ex->env, tk->content) == 1)
			flag = 1;
		tk = tk->next;
	}
	return (flag);
}
