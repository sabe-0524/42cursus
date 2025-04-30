/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:17 by sabe              #+#    #+#             */
/*   Updated: 2025/04/30 16:27:15 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

t_tokenizer	*tokenizer(char *line)
{
	t_tokenizer	*tk;

	tk = init_tokenizer(line);
	while (tk->line[tk->line_i])
	{
		if (tk->state == STATE_GENERAL)
		{
			if (skip_space(tk))
				continue ;
			if (handle_quote_general(tk))
				continue ;
			if (handle_operator(tk))
				continue ;
			tk->line_i++;
		}
		if (tk->state == STATE_IN_QUOTE)
			in_quote(tk);
		if (tk->state == STATE_IN_DQUOTE)
			in_dquote(tk);
	}
	if (tk->state == STATE_GENERAL)
	{
		add_token(tk);
	}
	else
	{
		printf("syntax_error\n");
	}
	return (tk);
}
