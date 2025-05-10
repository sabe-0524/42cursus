/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:36:33 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 14:02:25 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	expand_token(t_token *token)
{
	t_expander	*ex;

	ex = init_expander();
	while (token->content[ex->line_i])
	{
		if (ex->quote_state == STATE_GENERAL)
		{
			if (ex_quote(token, ex))
				continue ;
			if (ex_dquote(token, ex))
				continue ;
			if (ex_dollar(token, ex))
				continue ;
			ex->line_i++;
		}
		else if (ex->quote_state == STATE_IN_QUOTE)
		{
			if (ex_quote_in_quote(token, ex))
				continue ;
			ex->line_i++;
		}
		else
		{
			if (ex_dollar(token, ex))
				continue ;
			if (ex_dquote_in_dquote(token, ex))
				continue ;
			ex->line_i++;
		}
	}
	add_command(token, ex);
	change_content(token, ex);
}

void	expand_word(t_node *node)
{
	t_token	*token;

	token = node->token;
	while (token)
	{
		expand_token(token);
		token = token->next;
	}
}
