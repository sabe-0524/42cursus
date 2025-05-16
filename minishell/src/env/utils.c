/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:55:08 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 18:07:16 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void free_item(t_item *item)
{
	if (item->data)
  {
    item->data = NULL;
		free(item->data);
  }
	if (item->key)
  {
    item->key = NULL;
		free(item->key);
  }
  item = NULL;
	free(item);
}

void free_env(t_env *env)
{
	t_item *tmp;

	while (env->head)
	{
		tmp = env->head->next;
		free_item(env->head);
		env->head = tmp;
	}
	free(env);
}
