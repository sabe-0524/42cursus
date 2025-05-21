/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:55:08 by sabe              #+#    #+#             */
/*   Updated: 2025/05/21 17:04:47 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void	free_item(t_item *item)
{
	if (item->data)
		free(item->data);
	if (item->key)
		free(item->key);
	free(item);
}

void	free_env(t_env *env)
{
	t_item	*tmp;

	while (env->head)
	{
		tmp = env->head->next;
		free_item(env->head);
		env->head = tmp;
	}
	free(env);
}
