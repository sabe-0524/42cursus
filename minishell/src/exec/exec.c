/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:25:12 by sabe              #+#    #+#             */
/*   Updated: 2025/05/22 19:41:40 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	exec(t_tree *tree, t_env *env)
{
	t_executor	*ex;

	ex = init_ex(tree, env);
	recur_ex(tree->head, ex);
	all_free_executor(ex);
}
