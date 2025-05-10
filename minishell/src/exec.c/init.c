/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:28:22 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 18:14:49 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

t_executor	*init_ex(t_tree *tree)
{
	t_executor	*ex;

	ex = (t_executor *)ft_calloc(1, sizeof(t_executor));
	if (!ex)
	{
		exit(1); // TODO
	}
	ex->tree = tree;
	ex->in_fd = -1;
	ex->out_fd = -1;
	return (ex);
}
