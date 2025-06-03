/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:28:22 by sabe              #+#    #+#             */
/*   Updated: 2025/06/03 17:33:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

extern char	**environ;

t_executor	*init_ex(t_tree *tree, t_env *env)
{
	t_executor	*ex;

	ex = (t_executor *)ft_calloc(1, sizeof(t_executor));
	if (!ex)
	{
		exit(1);
	}
	ex->tree = tree;
	ex->pipe_fd[0] = -1;
	ex->pipe_fd[1] = -1;
	ex->in_fd = STDIN_FILENO;
	ex->out_fd = STDOUT_FILENO;
	ex->save_in = STDIN_FILENO;
	ex->pid = -1;
	ex->env = env;
	ex->use_pipe = false;
	return (ex);
}
