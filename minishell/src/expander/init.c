/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:19:35 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:56:15 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

t_expander	*init_expander(t_env *env)
{
	t_expander	*ex;

	ex = (t_expander *)ft_calloc(1, sizeof(t_expander));
	if (!ex)
	{
		exit(1);
	}
	ex->env = env;
	return (ex);
}
