/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:39:05 by sabe              #+#    #+#             */
/*   Updated: 2025/05/15 21:23:01 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	ex_echo(t_node *node, t_executor *ex)
{
	t_token	*tk;
	int		flag;

	flag = 0;
	tk = node->token->next;
	while (tk)
	{
		if (ft_strncmp(tk->content, "-n", 2) == 0 && tk->content[2] == '\0')
		{
			flag += 1;
			tk = tk->next;
			continue ;
		}
		ft_putstr_fd(tk->content, ex->out_fd);
		tk = tk->next;
		if (tk)
			ft_putstr_fd(" ", ex->out_fd);
	}
	if (!flag)
		ft_putstr_fd("\n", ex->out_fd);
}
