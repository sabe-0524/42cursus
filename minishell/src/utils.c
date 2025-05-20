/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:37:59 by sabe              #+#    #+#             */
/*   Updated: 2025/05/20 14:44:20 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (true);
		i++;
	}
	return (false);
}

void free_for_next(t_parser *ps, t_tokenizer *tk)
{
   all_free_tokenizer(tk);
   all_free_parser(ps);
}