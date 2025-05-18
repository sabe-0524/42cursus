/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:23:50 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 16:42:20 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_exit(t_node *node, t_executor *ex)
{
	if (count_token(node) > 2)
	{
		ft_putendl_fd("exit: too many arguments", 2);
		exit(EXIT_FAILURE);
	}
	else if (count_token(node) == 2)
		exit(ft_atoi(node->token->next->content));
	else
		exit(ft_atoi(my_getenv("?", ex->env)));
	return (EXIT_SUCCESS);
}
