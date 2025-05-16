/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:14:35 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/16 18:14:42 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void ex_unset(t_node *node, t_executor *ex)
{
  t_token	*tk;

  tk = node->token;
  while (tk)
  {
    my_unset(ex->env, tk->content);
    tk = tk->next;
  }
}