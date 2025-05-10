/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:04:48 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 14:07:48 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	free_expander(t_expander *ex)
{
	t_command	*tmp;

	while (ex->command)
	{
		tmp = ex->command->next;
		if (!ex->command->is_env)
			free(ex->command->content);
		free(ex->command);
		ex->command = tmp;
	}
	free(ex);
}
