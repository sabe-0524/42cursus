/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:57:20 by sabe              #+#    #+#             */
/*   Updated: 2025/05/21 14:50:18 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void	insert_env(t_env *env, t_item *item)
{
	t_item	*tmp;

	if (env->head == NULL)
	{
		env->head = item;
		item->prev = NULL;
		return ;
	}
	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, item->key, ft_strlen(item->key) + 1) == 0)
		{
			free(tmp->data);
			tmp->data = item->data;
			if (item->key)
				free(item->key);
			free(item);
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

void	my_setenv_row(t_env *env, char *key, char *data)
{
	t_item	*item;

	item = (t_item *)ft_calloc(1, sizeof(t_item));
	item->key = ft_strdup(key);
	// if (!item->key)
	// 	a();
	item->data = data;
	insert_env(env, item);
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
