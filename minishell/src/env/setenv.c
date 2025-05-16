/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:57:20 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 18:10:05 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void	insert_env(t_env *env, t_item *item)
{
	t_item	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, item->key, ft_strlen(item->key) + 1) == 0)
		{
			free(tmp->data);
			tmp->data = item->data;
			free_item(item);
			return ;
		}
		if (!tmp->next)
		{
			tmp->next = item;
			item->prev = tmp;
      return ;
		}
    tmp = tmp->next;
	}
}

void	my_setenv(t_env *env, char *str)
{
	char	*equal;
	t_item	*item;

	equal = ft_strchr(str, '=');
	if (!equal)
		return ;
	item = (t_item *)ft_calloc(1, sizeof(t_item));
	item->key = ft_substr(str, 0, (size_t)(equal - str));
	// if (!item->key)
	// 	a();
	item->data = ft_strdup(equal + 1);
	insert_env(env, item);
}
