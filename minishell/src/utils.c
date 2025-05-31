/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:37:59 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:23:14 by sabe             ###   ########.fr       */
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

void	free_for_next(t_parser *ps, t_tokenizer *tk)
{
	free_tokenizer(tk);
	all_free_parser(ps);
}
