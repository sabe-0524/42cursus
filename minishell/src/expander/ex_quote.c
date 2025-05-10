/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:43:02 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 13:39:57 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	ex_quote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\'')
		return (false);
	ex->quote_state = STATE_IN_QUOTE;
	add_command(token, ex);
	ex->line_i++;
	ex->start_i++;
	return (true);
}

bool	ex_dquote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\"')
		return (false);
	ex->quote_state = STATE_IN_DQUOTE;
	add_command(token, ex);
	ex->line_i++;
	ex->start_i++;
	return (true);
}

bool	ex_quote_in_quote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\'')
		return (false);
	ex->quote_state = STATE_GENERAL;
	add_command(token, ex);
	ex->start_i++;
	ex->line_i++;
	return (true);
}

bool	ex_dquote_in_dquote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\"')
		return (false);
	ex->quote_state = STATE_GENERAL;
	add_command(token, ex);
	ex->start_i++;
	ex->line_i++;
	return (true);
}
