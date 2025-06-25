/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:23:50 by sabe              #+#    #+#             */
/*   Updated: 2025/06/25 21:58:06 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

bool	is_numeric(t_token *tk)
{
	char	*content;
	size_t	i;

	i = 0;
	content = tk->content;
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
	ft_putendl_fd("exit", 2);
	if (count_token(node) == 1)
		exit(ft_atoi(my_getenv("?", ex->env)));
	else if (!is_numeric(node->token->next))
	{
		ft_putendl_fd("numeric argument required", 2);
		exit(2);
	}
	else if (count_token(node) == 2)
	{
		exit(ft_atoi(node->token->next->content) % 256);
	}
	else
		ft_putendl_fd("exit: too many arguments", 2);
	return (EXIT_FAILURE);
}
