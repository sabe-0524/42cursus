/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:43:02 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 13:08:44 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	ex_quote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\'')
		return (false);
	ex->quote_state = QUOTE;
	add_command(token, ex);
	ex->line_i++;
	ex->start_i++;
}

bool	ex_dquote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\"')
		return (false);
	ex->quote_state = DQUOTE;
	add_command(token, ex);
	ex->line_i++;
	ex->start_i++;
}

bool	ex_quote_in_quote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\'')
		return (false);
	ex->quote_state = GENERAL;
	add_command(token, ex);
	ex->start_i++;
	ex->line_i++;
	return (true);
}

bool	ex_dquote_in_dquote(t_token *token, t_expander *ex)
{
	if (token->content[ex->line_i] != '\"')
		return (false);
	ex->quote_state = GENERAL;
	add_command(token, ex);
	ex->start_i++;
	ex->line_i++;
	return (true);
}
