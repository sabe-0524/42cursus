/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:39:05 by sabe              #+#    #+#             */
/*   Updated: 2025/06/17 14:38:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

bool	is_option(char *s)
{
	size_t	i;

	i = 1;
	if (s[0] != '-')
		return (false);
	while (s[i])
	{
		if (s[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	ex_echo(t_node *node, t_executor *ex)
{
	t_token	*tk;
	int		flag;

	flag = 0;
	tk = node->token->next;
	while (tk)
	{
		if (is_option(tk->content))
		{
			flag = 1;
			tk = tk->next;
		}
		else
			break ;
	}
	while (tk)
	{
		ft_putstr_fd(tk->content, ex->out_fd);
		tk = tk->next;
		if (tk)
			ft_putstr_fd(" ", ex->out_fd);
	}
	if (!flag)
		ft_putstr_fd("\n", ex->out_fd);
	return (EXIT_SUCCESS);
}
