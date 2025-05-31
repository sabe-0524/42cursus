/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:22:25 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/31 18:42:24 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_env(t_executor *ex)
{
	char	**envp;
	size_t	i;

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
