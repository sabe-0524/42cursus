/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:58:52 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/31 18:38:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void	all_free_env(t_env *env)
{
	t_item	*tmp;

	if (!env)
		return ;
	while (env->head)
	{
		tmp = env->head->next;
		free(env->head->key);
		free(env->head->data);
		free(env->head);
		env->head = tmp;
	}
	free(env);
}
