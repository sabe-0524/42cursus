/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:24:27 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:37:36 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void	cut_env(t_item *item, t_env *env)
{
	if (!item->next && !item->prev)
		env->head = NULL;
	else if (!item->prev)
	{
		env->head = item->next;
		env->head->prev = NULL;
	}
	else if (!item->next)
		item->prev->next = NULL;
	else
	{
		item->prev->next = item->next;
		item->next->prev = item->prev;
	}
	free_item(item);
}

void	my_unset(t_env *env, char *key)
{
	t_item	*item;
	size_t	len;

	item = env->head;
	len = ft_strlen(key) + 1;
	while (item)
	{
		if (ft_strncmp(key, item->key, len) == 0)
		{
			cut_env(item, env);
			return ;
		}
		item = item->next;
	}
}
