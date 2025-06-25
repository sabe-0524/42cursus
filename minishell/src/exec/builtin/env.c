/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:22:25 by abesouichir       #+#    #+#             */
/*   Updated: 2025/06/25 19:59:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_env(t_node *node, t_executor *ex)
{
	char	**envp;
	size_t	i;

	if (node->token->next)
	{
		ft_putendl_fd("No such file or derectory", 2);
		return (127);
	}
	envp = catenv(ex->env);
	i = 0;
	while (envp[i])
	{
		if (envp[i][0] != '?')
			ft_putendl_fd(envp[i], ex->out_fd);
		i++;
	}
	all_free_paths(envp);
	return (EXIT_SUCCESS);
}
