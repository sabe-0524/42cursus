/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:19:35 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 16:24:26 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	init_expander(t_tree *tree)
{
	t_expander	*ex;

	ex = (t_expander *)ft_calloc(1, sizeof(t_expander));
	if (!ex)
	{
		exit(1); // TODO
	}
	ex->tree = tree;
}
