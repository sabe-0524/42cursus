/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:55:30 by sabe              #+#    #+#             */
/*   Updated: 2025/04/30 16:27:07 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

bool	is_space(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (true);
	else
		return (false);
}

bool	skip_space(t_tokenizer *tokenizer)
{
	if (!is_space(tokenizer->line[tokenizer->line_i]))
		return (false);
	add_token(tokenizer);
	while (is_space(tokenizer->line[tokenizer->line_i]))
	{
		tokenizer->line_i++;
		tokenizer->start_i++;
	}
	return (true);
}
