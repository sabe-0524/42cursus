/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:16 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 14:16:52 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

char	*my_getenv(char *key, t_env *env)
{
	t_item	*item;
	size_t	len;

	item = env->head;
	len = ft_strlen(key) + 1;
	while (item)
	{
		if (ft_strncmp(key, item->key, len) == 0)
			return (item->data);
		item = item->next;
	}
	return (NULL);
}
