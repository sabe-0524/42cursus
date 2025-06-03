/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:25:12 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:44:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	exec(t_tree *tree, t_env *env)
{
	t_executor	*ex;
	int			status;
	pid_t		wpid;

	ex = init_ex(tree, env);
	recur_ex(tree->head, ex);
	while (1)
	{
		wpid = wait(&status);
		if (wpid == -1)
		{
			if (errno == ECHILD)
				break ;
			else
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
		if (wpid == ex->pid)
		{
			my_setenv_row(ex->env, "?", ft_itoa(WEXITSTATUS(status)));
		}
	}
	all_free_executor(ex);
}
