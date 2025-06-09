/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:23:50 by sabe              #+#    #+#             */
/*   Updated: 2025/06/09 17:42:52 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

bool	is_numeric(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		if (!(('0' <= content[i] && content[i] <= '9') || (i == 0
					&& (content[i] == '-' || content[i] == '+'))))
			return (false);
		i++;
	}
	return (true);
}

int	ex_exit(t_node *node, t_executor *ex)
{
	if (count_token(node) > 2)
	{
		ft_putendl_fd("exit: too many arguments", 2);
		exit(EXIT_FAILURE);
	}
	else if (count_token(node) == 2)
	{
		if (is_numeric(node->token->next->content))
			exit(ft_atoi(node->token->next->content) % 256);
		else
			exit(2);
	}
	else
		exit(ft_atoi(my_getenv("?", ex->env)));
	return (EXIT_SUCCESS);
}

