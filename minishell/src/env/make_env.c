/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:26:28 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:37:34 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

t_item	*get_last_item(t_env *env)
{
	t_item	*item;

	item = env->head;
	while (item->next)
		item = item->next;
	return (item);
}

void	add_env_last(t_env *env, char *str)
{
	t_item	*item;
	char	*equal;
	t_item	*last;

	item = (t_item *)ft_calloc(1, sizeof(t_item));
	equal = ft_strchr(str, '=');
	item->key = ft_substr(str, 0, (size_t)(equal - str));
	item->data = ft_strdup(equal + 1);
	if (!env->head)
		env->head = item;
	else
	{
		last = get_last_item(env);
		last->next = item;
		item->prev = last;
	}
}

t_env	*init_env(char **envp)
{
	t_env	*env;
	int		i;

	i = 0;
	env = (t_env *)ft_calloc(1, sizeof(t_env));
	while (envp[i])
	{
		add_env_last(env, envp[i]);
		i++;
	}
	return (env);
}
