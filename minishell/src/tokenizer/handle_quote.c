/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:00:55 by sabe              #+#    #+#             */
/*   Updated: 2025/04/28 22:04:16 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

bool handle_quote_general(t_tokenizer *tokenizer)
{
	if (tokenizer->line[tokenizer->line_i] == '\'')
	{
		tokenizer->state = STATE_IN_QUOTE;
		tokenizer->line_i++;
		tokenizer->start_i++;
		return (true);
	}
	if (tokenizer->line[tokenizer->line_i] == '\"')
	{
		tokenizer->state = STATE_IN_DQUOTE;
		tokenizer->line_i++;
		tokenizer->start_i++;
		return (true);
	}
	return (false);
}
