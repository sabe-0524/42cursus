/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:12:57 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 15:25:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

size_t	count_env(t_env *env)
{
	t_item	*item;
	size_t	count;

	item = env->head;
	count = 0;
	while (item)
	{
		count++;
		item = item->next;
	}
	return (count);
}

char	*recover_env(t_item *item)
{
	char	*envp_i;
	size_t	len;

	len = ft_strlen(item->key) + ft_strlen(item->data) + 2;
	envp_i = (char *)ft_calloc(len, sizeof(char));
	ft_strlcat(envp_i, item->key, len);
	ft_strlcat(envp_i, "=", len);
	ft_strlcat(envp_i, item->data, len);
	return (envp_i);
}

char	**catenv(t_env *env)
{
	t_item	*item;
	size_t	count;
	char	**envp;
	size_t	i;

	i = 0;
	item = env->head;
	count = count_env(env);
	envp = (char **)ft_calloc((count + 1), sizeof(char *));
	while (item)
	{
		envp[i] = recover_env(item);
		i++;
		item = item->next;
	}
	return (envp);
}
