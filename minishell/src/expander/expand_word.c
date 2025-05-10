/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:36:33 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 12:42:46 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	is_separator(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('1' <= c
			&& c <= '9') || c == '_')
		return (true);
	else
		return (false);
}

void	expand_token(t_token *token)
{
	t_expander	*ex;

	ex = init_expander();
	while (token->content[ex->line_i])
	{
		if (ex->quote_state == GENERAL)
		{
			if (ex_quote(token, ex))
				continue ;
			if (ex_dquote(token, ex))
				continue ;
			if (ex_dollar(token, ex))
				continue ;
			ex->line_i++;
		}
		else if (ex->quote_state == QUOTE)
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
