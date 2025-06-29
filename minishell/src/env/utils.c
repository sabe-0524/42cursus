/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:55:08 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 21:28:33 by sabe             ###   ########.fr       */
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ptr;
	size_t	count1;
	size_t	count2;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	count1 = 0;
	count2 = 0;
	while (s1[count1] != '\0')
	{
		ptr[count1] = s1[count1];
		count1++;
	}
	while (s2[count2] != '\0')
	{
		ptr[count1 + count2] = s2[count2];
		count2++;
	}
	ptr[count1 + count2] = '\0';
	free(s1);
	free(s2);
	return (ptr);
}

int	handle_assignment(t_env *env, char *str, char *equal)
{
	t_item	*item;
	bool	is_add;

	item = ft_calloc(1, sizeof(t_item));
	is_add = false;
	if (*(equal - 1) == '+')
	{
		if (equal - 1 == str)
		{
			ft_putendl_fd("not a valid identifier", STDERR_FILENO);
			return (1);
		}
		item->key = ft_substr(str, 0, equal - str - 1);
		is_add = true;
	}
	else
	{
		item->key = ft_substr(str, 0, equal - str);
	}
	item->data = ft_strdup(equal + 1);
	if (!is_available_env(item->key))
	{
		ft_putendl_fd("not a valid identifier", STDERR_FILENO);
		free_item(item);
		return (1);
	}
	insert_env(env, item, is_add);
	return (0);
}

int	handle_no_assignment(char *str)
{
	if (is_available_env(str))
		return (0);
	ft_putendl_fd("not a valid identifier", STDERR_FILENO);
	return (1);
}
