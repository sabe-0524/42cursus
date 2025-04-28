/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:10:46 by sabe              #+#    #+#             */
/*   Updated: 2025/04/28 23:09:22 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

bool	is_operator(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (true);
	else
		return (false);
}

bool	handle_operator(t_tokenizer *tokenizer)
{
	if (!is_operator(tokenizer->line[tokenizer->line_i]))
		return (false);
	add_token(tokenizer);
	add_token_operator(tokenizer);
	return (true);
}
