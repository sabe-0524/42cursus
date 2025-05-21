/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:57:20 by sabe              #+#    #+#             */
/*   Updated: 2025/05/21 21:32:41 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

bool	is_available_env(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && ('0' <= s[i] && s[i] <= '9'))
			return (false);
		if (!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')
				|| ('0' <= s[i] && s[i] <= '9') || s[i] == '_'))
			return (false);
		i++;
	}
	return (true);
}

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

int	my_setenv(t_env *env, char *str)
{
	char	*equal;
	t_item	*item;

	equal = ft_strchr(str, '=');
	if (equal && equal != str)
	{
		item = (t_item *)ft_calloc(1, sizeof(t_item));
		item->key = ft_substr(str, 0, (size_t)(equal - str));
		item->data = ft_strdup(equal + 1);
		if (!is_available_env(item->key))
		{
			free_item(item);
			return (1);
		}
		insert_env(env, item);
	}
	else
	{
		if (is_available_env(str))
			return (0);
		else
			return (1);
	}
	return (0);
}
