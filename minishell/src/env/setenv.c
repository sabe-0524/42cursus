/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:57:20 by sabe              #+#    #+#             */
/*   Updated: 2025/06/17 14:26:52 by sabe             ###   ########.fr       */
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

void	search_env(t_item *tmp, t_item *item, bool is_add)
{
	while (tmp)
	{
		if (ft_strncmp(tmp->key, item->key, ft_strlen(item->key) + 1) == 0)
		{
			if (is_add)
				tmp->data = ft_strjoin_free(tmp->data, item->data);
			else
			{
				free(tmp->data);
				tmp->data = item->data;
			}
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

void	insert_env(t_env *env, t_item *item, bool is_add)
{
	t_item	*tmp;

	if (env->head == NULL)
	{
		env->head = item;
		item->prev = NULL;
		return ;
	}
	tmp = env->head;
	search_env(tmp, item, is_add);
}

void	my_setenv_row(t_env *env, char *key, char *data)
{
	t_item	*item;

	item = (t_item *)ft_calloc(1, sizeof(t_item));
	item->key = ft_strdup(key);
	item->data = data;
	insert_env(env, item, false);
}

int	my_setenv(t_env *env, char *str)
{
	char	*equal;

	equal = ft_strchr(str, '=');
	if (equal && equal != str)
		return (handle_assignment(env, str, equal));
	else
		return (handle_no_assignment(str));
}
